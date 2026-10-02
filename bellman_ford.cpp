#include <iostream>
#include <vector>
#include <climits>

using namespace std;

struct Edge {
    int src, dest, weight;
};

void bellmanFord(int V, int E, int source, const vector<Edge>& edges) {
    vector<int> dist(V, INT_MAX);
    dist[source] = 0;

    for (int i = 1; i <= V - 1; ++i) {
        bool updated = false;
        for (int j = 0; j < E; ++j) {
            int u = edges[j].src;
            int v = edges[j].dest;
            int weight = edges[j].weight;            
            if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                updated = true;
            }
        }
        if (!updated) break;
    }

    for (int j = 0; j < E; ++j) {
        int u = edges[j].src;
        int v = edges[j].dest;
        int weight = edges[j].weight;
        
        if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
            cout << "negative weight cycle! Shortest paths are undefined.\n";
            return;
        }
    }

    cout << "Vertex Distance from Source (" << source << "):\n";
    for (int i = 0; i < V; ++i) {
        if (dist[i] == INT_MAX) {
            cout << i << " : INF\n";
        } else {
            cout << i << " : " << dist[i] << "\n";
        }
    }
}

int main() {
    int V = 5; 
    int E = 8; 
    vector<Edge> edges = {
        {0, 1, -1}, {0, 2, 4},  {1, 2, 3}, {1, 3, 2},
        {1, 4, 2},  {3, 2, 5},  {3, 1, 1}, {4, 3, -3}
    };

    bellmanFord(V, E, 0, edges);

    return 0;
}
