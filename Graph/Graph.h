#ifndef GRAPH_H
#define GRAPH_H
#include <stdlib.h>
#include <vector>

class GEdge;

// use adjacency list for vertex
class GVertex{
public:
	GVertex();
	GVertex(int, void*);
	GEdge* getEdge(GVertex*); 
	std::vector<GVertex*>& neighbVertices() {retrn mNeighbVertices};
	friend class GEdge;
	friend class Graph;

private:
	int mIndex;
	std::vector<GVertex*> mNeighbVertices;
	std::vector<GEdge*> mEdges;
	void* mAppData;
};

class GEdge
{
public:
	GEdge(GVertex*, GVertex*, void*);
	GVertex* opposite(GVertex*);
	friend class GVertex;
	friend class Graph;
	
private:
	GVertex* mV1;
	GVertex* mV2;
	void* mAppData;
	int mWeight;
};

class Graph
{
public:
	enum VertexColor
	{
		kWhite,
		kGray,
		kBlack
	};
	GVertex* addVertex(int, void*);
	GEdge* addEdge(GVertex*, GVertex*, void*);
	void dfsVisit(  VCSGVertex*		vertex, 
					int*			color,
					int*			d,
					int*			low,
					int*			numChildren,
					VCSGVertex**	pred,
					int&			time,
					VCSCollection&	edgeStack);
	void dfsAlgorithm();
	int numEdges() {return mEdges.size();}

private:
	std::vector<GVertex*> mVertices;
	std::vector<GEdge*> mEdges; 
};

#endif