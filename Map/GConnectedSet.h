#ifndef GConnectedSet_H
#define GConnectedSet_H

#include <vector>
#include "GBiConnectedSet.h"

class GGraph;

class GConnectedSet 
{
public:
    GConnectedSet();

    void append(GBiConnectedSet*);
    void setGraph(GGraph*);
	GGraph* getOwingGraph();
    std::vector<GBiConnectedSet*>& biConnectedSets();

private:
    GGraph* mGraph;             // which graph this connected set is in?
    std::vector<GBiConnectedSet*> mBiConnectedSets;   // the bi-connected sets in this connected set
};

#endif