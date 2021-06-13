#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

using namespace std;

class Graph
{
private:
	vector<string> vertices;
	vector<vector<bool>> edges;
	int size;

	void addEdge(int fromLoc, int toLoc)
	{
		//As sir had placed 1 in the 2D matrixs displayed by him,however we can place any required weight.
		edges[fromLoc][toLoc] = true;
	}

	void ExploreNetwork(int vertexNo, vector<bool> &seen)
	{
		if (seen[vertexNo] == false)
		{
			seen[vertexNo] = true;

			cout << getVertex(vertexNo) << " visited" << endl;
			for (int i = 0; i < edges[vertexNo].size(); i++)
			{
				if (edges[vertexNo][i] == true)
					ExploreNetwork(i, seen);
			}
		}
	}

public:
	Graph(int verticesCount)
	{
		vertices.resize(verticesCount);
		edges.resize(verticesCount);
		for (int i = 0; i < verticesCount; i++)
		{
			edges[i].resize(verticesCount);
			edges[i].assign(verticesCount, false);
		}

		size = 0;
	}

	string getVertex(int vno)
	{
		return vertices[vno];
	}

	void addVertex(string st)
	{
		//It will add the vertice name on the size'th index of the vector.
		// vertices.emplace(vertices.begin() + size, st);
		vertices[size] = st;
		size++;
	}

	int findVertex(string st)
	{
		for (int j = 0; j < vertices.size(); j++)
		{
			if (vertices[j] == st)
			{
				return j;
			}
		}
		return -1;
	}

	void addDirectedEdge(string from, string to)
	{
		int fromLoc = findVertex(from);
		int toLoc = findVertex(to);

		if (fromLoc == -1 || toLoc == -1)
		{
			exit(0); // exception
		}
		addEdge(fromLoc, toLoc);
	}

	void addUnDirectedEdge(string from, string to)
	{
		int fromLoc = findVertex(from);
		int toLoc = findVertex(to);

		if (fromLoc == -1 || toLoc == -1)
		{
			exit(0); // exception
		}
		addEdge(fromLoc, toLoc);
		addEdge(toLoc, fromLoc);
	}

	void TraverseReachableGraph(string start)
	{
		vector<bool> chk(size, false);
		int vno = findVertex(start);
		if (vno == -1)
		{
			exit(0); // exception
		}
		ExploreNetwork(vno, chk);
	}
	void TraverseReachableGraph()
	{
		vector<bool> chk(size, false);
		ExploreNetwork(0, chk);
	}
	void TraverseCompleteGraph()
	{
		vector<bool> t(size, false);
		for (int j = 0; j < size; j++)
		{
			if (t[j] == false)
			{
				cout << "starting traversal ..." << endl;
				ExploreNetwork(j, t);
			}
		}
	}
};

int main()
{
	Graph f(7);
	f.addVertex("B");
	f.addVertex("R");
	f.addVertex("N");
	f.addVertex("F");
	f.addVertex("A");
	f.addVertex("P");
	f.addVertex("Y");

	f.addDirectedEdge("R", "N");
	f.addDirectedEdge("B", "F");
	f.addDirectedEdge("A", "P");
	f.addDirectedEdge("R", "A");
	f.addDirectedEdge("P", "F");
	f.addDirectedEdge("N", "B");
	f.addDirectedEdge("Y", "N");
	f.addDirectedEdge("Y", "F");
	f.addDirectedEdge("Y", "A");
	f.addDirectedEdge("R", "B");

	cout << endl
		 << "Explore Reachable Graph starting from" << endl;
	cout << "=============" << endl;
	f.TraverseReachableGraph("Y");
	cout << endl
		 << "Explore Reachable Graph starting from" << endl;
	cout << "=============" << endl;
	f.TraverseReachableGraph();
	cout << endl
		 << "Explore Complete Graph starting from" << endl;
	cout << "=============" << endl;
	f.TraverseCompleteGraph();
}
