#include "GVertex.h"
#include "GEdge.h"

using namespace std;

GVertex::GVertex()
	: mIndex(0), mAppData(NULL)
{
}

GVertex::GVertex(int index, void* AppData)
	: mIndex(index), mArtiPoint(false), mAppData(AppData)
{
	mWeight = 0;
	mPrevious = NULL;
	mDist = 0;
}


std::vector<GVertex*>& GVertex::neighbVertices() {
	return mNeighbVertices;
}

std::vector<GEdge*>& GVertex::edges() {
	return mEdges;
}

void GVertex::setIndex(int i) {
	mIndex = i;
}

int GVertex::index() {
	return mIndex;
}

void GVertex::setAppData(void* d) {
	mAppData = d;
}

void* GVertex::appData() {
	return mAppData;
}

void GVertex::setArtiPoint(bool a) {
    mArtiPoint = a;
}

bool GVertex::isArtiPoint() {
    return mArtiPoint;
}

double GVertex::getWeight() {
    return mWeight;
}

void GVertex::setWeight(double weight) {
    mWeight = weight;
}

GVertex* GVertex::getPrevious() {
	return mPrevious;
}

void GVertex::setPrevious(GVertex* v) {
	mPrevious = v;
}

double GVertex::getDist() {
	return mDist;
}

void GVertex::setDist(double dist) {
	mDist = dist;
}

GEdge* GVertex::getEdge(GVertex* v)
{
	auto iter = mEdges.begin();
	while(iter != mEdges.end())
	{
		auto oldIter = iter;
		++iter;
		if(v == (*oldIter)->opposite(this))
			return *oldIter;
	}
	return NULL;
}

std::vector<GBiConnectedSet*> GVertex::getBiConnectedSets() 
{
    vector<GBiConnectedSet*> biSets;

    GEdge* edge = NULL;
    auto iter = mEdges.begin();
    while (iter++ != mEdges.end())
        biSets.push_back(edge->biSet());

    return biSets;
}