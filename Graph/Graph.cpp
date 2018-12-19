#include "stdafx.h"
#include "Map.h"

GVertex::GVertex()
	: mIndex(0), mAppData(NULL)
{
}

GVertex::GVertex(int index, void* AppData)
	: mIndex(index), mAppData(AppData)
{
}

GEdge* GVertex::getEdge(GVertex* V)
{
	auto iter = mEdges.begin();
	while(iter++ != mEdges.end())
	{
		if(V == (*iter)->opposite(this))
			return *iter;
	}
	return NULL;
}

GEdge::GEdge(GVertex* V1, GVertex* V2, void* AppData)
	:mV1(V1), mV2(V2), mAppData(AppData)
{
	mWeight = 0;
}

GVertex* GEdge::opposite(GVertex* V)
{
	if(V == mV1)
		return mV2;
	else if(V == mV2)
		return mV1;
	else return NULL;
}

GVertex* Graph::addVertex(int index, void* AppData)
{
	GVertex* V = new GVertex(index, AppData);
	mVertices.push_back(V);
	return V;
}

GEdge* Graph::addEdge(GVertex* V1, GVertex* V2, void* AppData)
{
	if(V1 != V2)
	{
		GEdge* edge = V1->getEdge(V2);
		if(edge == NULL){
			edge = new GEdge(V1, V2, AppData);
			mEdges.push_back(edge);
		}
	}else
		return NULL;
}

/*
DFS_ALGORITHM
for each vertex v in vertices
	set color[v] == white
set time == 0
for each vertex v in vertices
	if color[v] == white //v is a new tree in DFS
		DFS_VISIT(v)

DFS_VISIT[]		 
set color[v] == grey //when v was found
record ++time in d[v] // time when v was found
for each adjacent vertex w of vertex v 
	if color[w] == white
		set w's parent as w
		DFS_VISIT[w]
set color[v] as black // v and all adjacent vertices are visited
record ++time in f[v]
*/

// Depth first searching
void Graph::dfsVisit(GVertex*			vertex, 
						int*			color,
						int*			d,
						int*			low,
						int*			numChildren,
						GVertex**		pred, // an array storing vertices' predecessors
						int&			time,
						std::vector<GEdge*>&	edgeStack)
{
	int v = vertex->mIndex;
	color[v] = kGray; // set it gray when found in searching
	low[v] = d[v] = ++time;

	if(!vertex->neighbVertices().empty())
	{
		auto iter = vertex->neighbVertices().begin();
		while(iter++ != vertex->neighbVertices().end())
		{
			GVertex* neighb = *iter;
			GEdge* edge = vertex->getEdge(neighb);
			int w = neighb->index();
			if(color[w] == kWhite)
			{
				pred[w] = vertex;
				numChildren[v]++;
				edgeStack.push(edge);

				dfsVisit(neighb, color, d, low, numChildren, pred, time, edgeStack)
			}
		}
	}
	color[v] = kBlack;
}


//DFS ALGORITHM
void Graph::dfsAlgorithm()
{
	int numVertices = mVertices.length();
	int*		 color		  = new int[numVertices];
	int*		 d			  = new int[numVertices];
	int*		 low		  = new int[numVertices];
	int*		 numChildren  = new int[numVertices];
	VCSGVertex** pred		  = new VCSGVertex*[numVertices];	

	// initialize
	for (int i = 0; i < numVertices; i++) {
		mVertices[i]->setIndex(i);
		color[i] = kWhite;
		pred[i] = NULL;
		numChildren[i] = 0;
	}

	int time = 0;
	std::vector<GEdge*> edgeStack;
	for (int i = 0; i < numVertices; i++) {
		if (color[i] == kWhite) {
			dfsVisit(mVertices[i], color, d, low, numChildren, pred, time, edgeStack);
		}
	} 

	delete []color;
	delete []d;
	delete []low;
	delete []numChildren;
	delete []pred;
}
