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

void GGraph::clearConnSet() {
    if (!mConnectedSets.empty()) {
        auto iter = mConnectedSets.begin();
		while (iter != mConnectedSets.end()) {
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

// Depth first searching
void GGraph::dfsVisit(GVertex* vertex, VertexColor*	color, int*	d, int* low, 
		int* numChildren, GVertex** pred, int& time, std::vector<GEdge*>& edgeStack)
{
	int v = vertex->index();
	color[v] = kGray; // set it gray when found in searching
	low[v] = d[v] = ++time;
}