#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Graph
{
    int V;                   // Number of vertices
    vector<vector<int>> adj; // Adjacency list

public:
    Graph(int V)
    {
        this->V = V;
        adj.resize(V);
    }

    // Function to add an edge to the graph
    void addEdge(int v, int w)
    {
        adj[v].push_back(w);
    }

    // Depth-First Search
    void DFS(int start)
    {
        vector<bool> visited(V, false); // Initialize all vertices as not visited
        stack<int> stack;

        // Push the starting vertex onto the stack
        stack.push(start);

        while (!stack.empty())
        {
            // Pop a vertex from the stack and print it
            int current = stack.top();
            stack.pop();

            if (!visited[current])
            {
                cout << current << " ";
                visited[current] = true;
            }

            // Get all adjacent vertices of the popped vertex
            // If an adjacent vertex has not been visited, push it to the stack
            for (int neighbor : adj[current])
            {
                if (!visited[neighbor])
                {
                    stack.push(neighbor);
                }
            }
        }
    }
};

int main()
{
    Graph g(5); // graph vertices

    g.addEdge(0, 1);
    g.addEdge(0, 3);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 4);

    cout << "Depth-First Traversal: ";
    g.DFS(0);

    return 0;
}
