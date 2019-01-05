#ifndef GGraph_H
#define GGraph_H

#include "GVertex.h"
#include "GEdge.h"
#include "GBiConnectedSet.h"
#include "GConnectedSet.h"
#include <vector>
#include "stdio.h"

class GGraph {
public:
	enum VertexColor {
		kWhite,
		kGray,
		kBlack
	};

	GGraph();
	~GGraph();
	
	GVertex* addVertex(int index, void* AppData = NULL);
	GEdge* addEdge(GVertex* V1, GVertex* V2, void* AppData = NULL);	

	void computeBiConnectedSets();	

	std::vector<GVertex*>& vertices();
	std::vector<GEdge*>&  edges();
    std::vector<GConnectedSet*>& connectedSets();
	std::vector<GBiConnectedSet*>&	biConnectedSets();
    std::vector<GVertex*>& articulationPoints();

	int numVertices();
	int	numEdges();
	
	void printGraph();
    void printGraphWithWeightedEdges();

	void dijkstra(GVertex*, std::vector<GVertex>& /*vertices to be searched, if empty, search the whole graph*/);
	int  findShortestPathWeighted(GVertex* /*start*/, GVertex* /*end*/, std::vector<GVertex>& /*path*/, bool = false /* count edge weight adjustment? */ );
	int  findShortestCirclePathWeighted(GVertex* /* vertex circle passed */, std::vector<GVertex>& /*circle path */, std::vector<GVertex>& /*vertices to be searched*/, bool = false /* count edge weight adjustment? */);

private:
	void dfsVisit(GVertex* vertex, VertexColor*	color, int*	d, int* low, 
		int* numChildren, GVertex** pred, int& time, std::vector<GEdge*>& edgeStack);

	void addNewBiConnSet(std::vector<GEdge*>&, GEdge*);
    void addNewBiConnSet(GVertex*);
    void addNewConnSet(GBiConnectedSet*);
	void append(GEdge*);
    void append(GConnectedSet*);
    void clearBiConnSet();
    void clearConnSet();
    void clearArtiPoints();

private:
	std::vector<GVertex*> mVertices;
	std::vector<GEdge*> mEdges;
	std::vector<GConnectedSet*> mConnectedSets;
	std::vector<GBiConnectedSet*> mBiConnectedSets;
	std::vector<GVertex*> mArtiPoints;
};

#endif