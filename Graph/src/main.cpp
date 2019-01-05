#include "GGraph.h"
#include <iostream>

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

	graph.printGraph();

	return 0;
}