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
	std::vector<GEdge*>::const_iterator iter = mEdges.begin();
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

// Depth first searching
void Graph::dfsVisit(GVertex*			vertex, 
						int*			color,
						int*			d,
						int*			low,
						int*			numChildren,
						GVertex**		pred,
						int&			time,
						std::vector<GEdge*>&	edgeStack)
{
	int v = vertex->mIndex;
	color[v] = kGray; // set it gray when found in searching
	low[v] = d[v] = ++time;
}

