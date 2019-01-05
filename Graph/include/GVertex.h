#ifndef GVertex_H
#define GVertex_H

#include <vector>

class GEdge;
class GBiConnectedSet;

class GVertex
{
public:
	GVertex();
	GVertex(int index, void* AppData = NULL);

	std::vector<GVertex*>& neighbVertices();
	std::vector<GEdge*>& edges();
	std::vector<GBiConnectedSet*> getBiConnectedSets();

	void setIndex(int);
	void setAppData(void*);
	void setArtiPoint(bool);
	bool isArtiPoint();
	int index();
	void* appData();
	double getWeight();
	void setWeight(double);
	GVertex* getPrevious();
	void setPrevious(GVertex*);
	double getDist();
	void setDist(double);
	GEdge* getEdge(GVertex*);

private:
	int mIndex;
	bool mArtiPoint;
	std::vector<GVertex*> mNeighbVertices;
	std::vector<GEdge*> mEdges;
	void* mAppData;
	double mWeight;
	GVertex* mPrevious; // used in shortest path finding
	double mDist; // used in shortest path finding
};

#endif