#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

struct Edge
{
    int src, dest, weight;
};

class Graph
{
public:
    int V, E;
    vector<Edge> edges;

    Graph(int v, int e)
    {
        V = v;
        E = e;
        edges.resize(e);
    }

    void addEdge(int src, int dest, int weight)
    {
        edges.push_back({src, dest, weight});
    }

    int findParent(vector<int>& parent, int node)
    {
        if (parent[node] == -1)
            return node;
        return findParent(parent, parent[node]);
    }

    void unionSets(vector<int>& parent, int x, int y)
    {
        int xRoot = findParent(parent, x);
        int yRoot = findParent(parent, y);
        parent[xRoot] = yRoot;
    }

    void kruskalMST()
    {
        vector<Edge> result;
        vector<int> parent(V, -1);

        sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b)
        {
            return a.weight < b.weight;
        });

        set<pair<int, int>> sortedEdgesSet; // To store unique edges
        cout << "Sorted Edges:" << endl;
        for (Edge edge : edges)
        {
            // Check if the edge already exists in the set
            if (sortedEdgesSet.find({edge.src, edge.dest}) == sortedEdgesSet.end() &&
                    sortedEdgesSet.find({edge.dest, edge.src}) == sortedEdgesSet.end())
            {
                sortedEdgesSet.insert({edge.src, edge.dest});
                cout << edge.src << " - " << edge.dest << " : " << edge.weight << endl;
            }
        }

        int edgeCount = 0;
        vector<bool> inMST(V, false);

        for (Edge edge : edges)
        {
            int srcRoot = findParent(parent, edge.src);
            int destRoot = findParent(parent, edge.dest);

            if (srcRoot != destRoot)
            {
                result.push_back(edge);
                unionSets(parent, srcRoot, destRoot);
                edgeCount++;
                inMST[edge.src] = true;
                inMST[edge.dest] = true;

                if (edgeCount == V - 1)
                    break;
            }
        }

        cout << endl << "Minimum Spanning Tree Edges:" << endl;
        for (Edge edge : result)
        {
            cout << edge.src << " - " << edge.dest << " : " << edge.weight << endl;
        }

        vector<int> mstVertices;
        for (int i = 0; i < V; i++)
        {
            if (inMST[i])
            {
                mstVertices.push_back(i);
            }
        }

        cout << endl << "Sorted Vertices:" << endl;
        sort(mstVertices.begin(), mstVertices.end());
        for (int vertex : mstVertices)
        {
            cout << vertex << " ";
        }
        cout << endl;
    }
};

int main()
{
    int V = 4; // Number of vertices
    int E = 5; // Number of edges
    Graph graph(V, E);

    // Add edges to the graph (src, dest, weight)
    graph.addEdge(0, 1, 10);
    graph.addEdge(0, 2, 6);
    graph.addEdge(0, 3, 5);
    graph.addEdge(1, 3, 15);
    graph.addEdge(2, 3, 4);

    // Find and print the minimum spanning tree and sorted edges
    graph.kruskalMST();

    return 0;
}
