#include "GGraph.h"

using namespace std;

GGraph::GGraph()
{
}

GGraph::~GGraph() {
	// clear vertices
	//
	if (!mVertices.empty()) {
		auto iter = mVertices.begin();
		while (iter != mVertices.end()) {
			delete *iter;
			++iter;
		}
	}
	
	// clear edges
	//
	if (!mEdges.empty()) {
		auto iter = mEdges.begin();
		while (iter != mEdges.end()) {
			delete *iter;
			++iter;
		}
	}
	
	// clear computed bi-connected sets
	//
    clearConnSet();
	clearBiConnSet();
}

std::vector<GVertex*>& GGraph::vertices()
{
	return mVertices;
}

std::vector<GEdge*>& GGraph::edges()
{
	return mEdges;
}

void GGraph::clearConnSet() {
    if (!mConnectedSets.empty()) {
        auto iter = mConnectedSets.begin();
		while (iter != mConnectedSets.end()) {
			delete *iter;
			++iter;
		}
    }
}

void GGraph::clearBiConnSet() {
	if (!mBiConnectedSets.empty()) {
		auto iter = mBiConnectedSets.begin();
		while (iter != mBiConnectedSets.end()) {
			delete *iter;
			++iter;
		}
	}
}

void GGraph::clearArtiPoints() {
    if (!mArtiPoints.empty()) {
        auto iter = mArtiPoints.begin();
        while (iter != mArtiPoints.end())
        {
            (*iter)->setArtiPoint(false);
        }

        mArtiPoints.clear();
    }
}

GVertex* GGraph::addVertex(int index, void* AppData)
{
	GVertex* v = new GVertex(index, AppData);
	mVertices.push_back(v);
	return v;
}

GEdge* GGraph::addEdge(GVertex* V1, GVertex* V2, void* AppData)
{
	if(V1 != V2)
	{
		GEdge* edge = V1->getEdge(V2);
		if(edge == NULL) {
			edge = new GEdge(V1, V2, AppData);
			append(edge);
		}
		return edge;
	}else
		return NULL;
}

void GGraph::append(GEdge* e) 
{
	mEdges.push_back(e);
}

void GGraph::append(GConnectedSet* c) 
{
    mConnectedSets.push_back(c);
    c->setGraph(this);
}

void GGraph::addNewBiConnSet(std::vector<GEdge*>& edgeStack, GEdge* toEdge) 
{
    // add a new bi-connected set, which contains edges
    GBiConnectedSet* newBiConnSet = new GBiConnectedSet();
    GEdge* edge = NULL;
    while ((edge = edgeStack.back()) != toEdge)
    {
    	edgeStack.pop_back();
        newBiConnSet->append(edge);
    }
    newBiConnSet->append(toEdge);

    mBiConnectedSets.push_back(newBiConnSet);	
}

// Add a new bi-connected set which has 1 vertex and 0 edge
void GGraph::addNewBiConnSet(GVertex* v) 
{
    GBiConnectedSet* newBiConnSet = new GBiConnectedSet(v);
    mBiConnectedSets.push_back(newBiConnSet);
}

// Add a new connected set
void GGraph::addNewConnSet(GBiConnectedSet* toBiConnSet) 
{
    // add a new connected set, which contains pointers to bi-connected sets
    GConnectedSet* newConnSet = new GConnectedSet();

    auto iter = mBiConnectedSets.end();
    GBiConnectedSet* biConnSet = NULL;
    while ((biConnSet = *(--iter)) != toBiConnSet) {
        newConnSet->append(biConnSet);
    }

    append(newConnSet);
}

void GGraph::printGraph() {
	FILE* file = fopen("_graph.txt", "w");

    fprintf(file, "// Found %d connected sets\n\n", (int)mConnectedSets.size());
	fprintf(file, "// Found %d articulation points and %d bi-connected sets\n\n", (int)mArtiPoints.size(), (int)mBiConnectedSets.size());

	fprintf(file, "\n\n graph A {\n node[shape=\"circle\"]\n");

	fprintf(file, "// articulation points \n");
	GVertex* vertex = NULL;
	auto vIter = mArtiPoints.begin();
	while (vIter != mArtiPoints.end()) {
		fprintf(file, " \"%d\" [ style = \"filled\", color=\"red\" ];\n", (*vIter)->index());
		++vIter;
	}

    auto cnIter = mConnectedSets.begin();
    int cnID = 0;
    while (cnIter != mConnectedSets.end()) {
        auto sIter = (*cnIter)->biConnectedSets().begin();
        int biID = 0;
        while (sIter != (*cnIter)->biConnectedSets().end()) {
            auto eIter = (*sIter)->edges().begin();
            while (eIter != (*sIter)->edges().end()) {
                fprintf(file, "%d -- %d [label=\"%d(%d)\"] \n", (*eIter)->v1()->index(), (*eIter)->v2()->index(), cnID, biID);
                ++eIter;
            }

            ++biID;
            ++sIter;
        }

        ++cnID;
        ++cnIter;
    }

	fprintf (file, " }\n");
	fclose(file);
}

// Depth first searching
void GGraph::dfsVisit(GVertex* vertex, VertexColor*	color, int*	d, int* low, 
		int* numChildren, GVertex** pred, int& time, std::vector<GEdge*>& edgeStack)
{
	int v = vertex->index();
	color[v] = kGray; // set it gray when found in searching
	low[v] = d[v] = ++time;
}