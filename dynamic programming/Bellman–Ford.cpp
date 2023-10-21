#include<iostream>// not needed for that
#include <bits/stdc++.h>
using namespace std;

void bellmanFord(int n, int m, int src, vector<pair<pair<int, int>, int>> adj)
{
    // creating an array to store the path length from source to i
    int path[n];
    // filling the array with max value
    for (int i = 0; i < n; i++)
        path[i] = INT_MAX;
    // distance from source to source is 0
    path[src] = 0;
    bool flag = false;
    // bellman ford algorithm
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j < adj.size(); j++)
        {
            // u node
            int u = adj[j].first.first;
            // v node
            int v = adj[j].first.second;
            // edge weight
            int wt = adj[j].second;
            if (i == n && path[v] > (path[u] + wt))
            {
                flag = true;
                cout << "There is a negative cycle in the graph" << endl;
                break;
            }
            // relaxation
            else if (i < n && path[u] != INT_MAX && path[v] > (path[u] + wt))
            {
                path[v] = path[u] + wt;
            }
        }
        if(flag) break; // If a negative cycle is found, break out of the loop early
    }
    // if there is no negative cyle
    if (!flag)
    {
        // then print the shortest path of every node from the source node
        for (int i = 0; i < n; i++)
        {
            cout <<"The shortest path between " << src <<" and " << i <<" is: ";
            if (path[i]==INT_MAX)
            {
                cout<<"No Path\n";
            }
            else
            {
                cout<< path[i] << endl;
            }
        }
    }
}

int main()
{
    int n = 5, m = 7, src = 0; // n= vertices, m= edge
    vector<pair<pair<int, int>, int>> adj;
    adj.push_back({{0, 1}, 2});
    adj.push_back({{1, 4}, 1});
    adj.push_back({{3, 4}, 3});
    adj.push_back({{3, 2}, 7});
    adj.push_back({{2, 0}, 5});
    adj.push_back({{2, 1}, -1});
    adj.push_back({{1, 3}, 10});


    bellmanFord(n, m, src, adj);
}
