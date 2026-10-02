#include<bits/stdc++.h>
using namespace std ;

typedef pair<int, int> pii;

void dijkstra(int src, const vector<vector<pii>>& adj, int V) {
    
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    vector<int> dist(V, INT_MAX);

    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (d > dist[u]) continue;

        for (const auto& edge : adj[u]) {
            int v = edge.first;
            int weight = edge.second;

            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    cout << "Vertex\tDistance from Source (" << src << ")\n";
    for (int i = 0; i < V; ++i) {
        cout << i << "\t";
        if (dist[i] == INT_MAX) cout << "INF\n";
        else cout << dist[i] << "\n";
    }
}

int main() {
    int V = 5; // Number of vertices
    vector<vector<pii>> adj(V);

    
    adj[0].push_back({1, 4});
    adj[0].push_back({2, 1});
    adj[1].push_back({0, 4});
    adj[1].push_back({2, 2});
    adj[1].push_back({3, 5});
    adj[2].push_back({0, 1});
    adj[2].push_back({1, 2});
    adj[2].push_back({3, 8});
    adj[2].push_back({4, 10});
    adj[3].push_back({1, 5});
    adj[3].push_back({2, 8});
    adj[3].push_back({4, 2});
    adj[4].push_back({2, 10});
    adj[4].push_back({3, 2});

    int source_node = 0;
    dijkstra(source_node, adj, V);

    return 0;
}