#include "GConnectedSet.h"

using namespace std;

void GConnectedSet::setGraph(GGraph* g) {
    mGraph = g;
}

GGraph* GConnectedSet::getOwingGraph() {
    return mGraph;
}

std::vector<GBiConnectedSet*>& GConnectedSet::biConnectedSets() {
    return mBiConnectedSets;
}

GConnectedSet::GConnectedSet()
: mGraph(NULL) 
{
}

void GConnectedSet::append(GBiConnectedSet* b) {
    mBiConnectedSets.push_back(b);
    b->setConnectedSet(this);
}