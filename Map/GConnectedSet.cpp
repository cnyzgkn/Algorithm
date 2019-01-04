#include "GConnectedSet.h"

using namepsace std;

void GConnectedSet::setGraph(Graph* g) {
    mGraph = g;
}

Graph* GConnectedSet::getOwingGraph() {
    return mGraph;
}

Collection& GConnectedSet::biConnectedSets() {
    return mBiConnectedSets;
}

GConnectedSet::GConnectedSet()
: mGraph(NULL) 
{
}

void GConnectedSet::append(GBiConnectedSet* b) {
    mBiConnectedSets.append(b);
    b->setConnectedSet(this);
}