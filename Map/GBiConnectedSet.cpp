#include "GBiConnectedSet.h"
#include "GConnectedSet.h"

using namespace std;

GBiConnectedSet::GBiConnectedSet(GVertex* v)
: mConnectedSet(NULL), mAppData(NULL)
{
    mVertices.push_back(v);
}

void GBiConnectedSet::setConnectedSet(GConnectedSet* c) {
    mConnectedSet = c;
}

Collection& GBiConnectedSet::edges() {
    return mEdges;
}

void* GBiConnectedSet::appData() {
    return mAppData;
}

void GBiConnectedSet::setAppData(void* d) {
    mAppData = d;
}

void GBiConnectedSet::append(GEdge* e) 
{
    if (e != NULL) {
        mEdges.push_back(e);
        e->setBiSet(this);
    }
}

std::vector<GVertex*>& GBiConnectedSet::vertices() 
{
    return mVertices;
}

std::vector<GVertex*>& GBiConnectedSet::articulationPoints() 
{
    return mArtiPoints;
}