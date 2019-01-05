#ifndef GEdge_H
#define GEdge_H

#include <vector>
#include "GVertex.h"

class GBiConnectedSet;

class GEdge
{
public:
	GEdge(GVertex* V1, GVertex* V2, void* AppData = NULL);
	GVertex* v1();
	GVertex* v2();
	GVertex* opposite(GVertex*);

	GBiConnectedSet* biSet();
	void setBiSet(GBiConnectedSet*);
	void* appData();
	double getWeight();
	void setWeight(double);
	void setActive(bool);
	bool isActive();

private:
	GVertex* mV1;
	GVertex* mV2;
	void* mAppData;
	GBiConnectedSet* mBiSet; //the bi-connected set that owns this edge
	double mWeight;	
	bool mActive;
};

#endif