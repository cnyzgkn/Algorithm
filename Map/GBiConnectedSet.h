#ifndef GBiConnectedSet_H
#define GBiConnectedSet_H

#include <vector>

class GEdge;
class GVertex;
class GConnectedSet;

class GBiConnectedSet {
public:
    GBiConnectedSet();
    GBiConnectedSet(GVertex*);

    void append(GEdge*);
    void setConnectedSet(GConnectedSet*);

    std::vector<GEdge*>& edges();
    std::vector<GVertex*>& vertices();
    std::vector<GVertex*>& articulationPoints();

	void* appData();
	void setAppData(void*);

private:
    std::vector<GConnectedSet*> mConnectedSet;      // which connected set this bi-connected set is in?
    std::vector<GEdge*> mEdges;             // the edges in this bi-connected set
    std::vector<GVertex*> mVertices;          // vertices in this bi-connected set, is computed from the edges
    std::vector<GVertex*> mArtiPoints;        // articulation points in this bi-connected set, is computed from the edges
	void* mAppData;
};

#endif