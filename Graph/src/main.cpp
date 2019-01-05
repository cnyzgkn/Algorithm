#include "GGraph.h"
#include <iostream>
#include <random>

using namespace std;

int main()
{
	cout << "init graph" << endl;
	GGraph graph;

	const int iVertexNum = 10;
	for(int i = 0; i < iVertexNum; ++i)
	{
		graph.addVertex(i);
	}

	vector<GVertex*> vertexArray = graph.vertices();
	std::default_random_engine random;
	for (auto itr = vertexArray.begin(); itr != vertexArray.end(); ++itr)
	{
		for (auto nextItr = itr + 1; nextItr != vertexArray.end(); ++nextItr)
		{
			graph.addEdge(*itr, *nextItr, random());
		}
	}

	graph.printGraph();

	return 0;
}