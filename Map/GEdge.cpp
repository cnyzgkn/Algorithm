#include "GEdge.h"

using namespace std;

GEdge::GEdge(GVertex* V1, GVertex* V2, void* AppData)
	:mV1(V1), mV2(V2), mAppData(AppData), mBiSet(NULL)
{
	mV1->neighbVertices().push_back(mV2);
	mV2->neighbVertices().push_back(mV1);
	mV1->edges().push_back(this);
	mV2->edges().push_back(this);
	mWeight = 0;
	mActive = true;
}

GVertex* GEdge::opposite(GVertex* v)
{
	if(v == mV1)
		return mV2;
	else if(v == mV2)
		return mV1;
	else return NULL;
}

GVertex* GEdge::v1() {
	return mV1;
}

GVertex* GEdge::v2() {
	return mV2;
}

void* GEdge::appData() {
	return mAppData;
}

GBiConnectedSet* GEdge::biSet() {
	return mBiSet;
}

void GEdge::setBiSet(GBiConnectedSet* s) {
	mBiSet = s;
}

double GEdge::getWeight() {
    return mWeight;
}

void GEdge::setWeight(double weight) {
	mWeight = weight;
}

bool GEdge::isActive() {
    return mActive;
}

void GEdge::setActive( bool bActive ) {
    mActive = bActive;
}
