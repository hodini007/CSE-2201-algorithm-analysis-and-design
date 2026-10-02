#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int src, dest, weight;
    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};

struct DSU {
    vector<int> parent, rank;
    DSU(int n) {
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
        rank.resize(n, 0);
    }
    int find(int i) {
        return parent[i] == i ? i : parent[i] = find(parent[i]);
    }
    bool unite(int i, int j) {
        int root1 = find(i), root2 = find(j);
        if (root1 != root2) {
            if (rank[root1] < rank[root2]) swap(root1, root2);
            parent[root2] = root1;
            if (rank[root1] == rank[root2]) rank[root1]++;
            return true;
        }
        return false;
    }
};

void kruskalMST(int V, vector<Edge>& edges) {
    sort(edges.begin(), edges.end());
    DSU dsu(V);
    int mst_weight = 0, edge_count = 0;

    cout << "Edges in the Minimum Spanning Tree:\n";
    for (const auto& edge : edges) {
        if (dsu.unite(edge.src, edge.dest)) {
            cout << edge.src << " -- " << edge.dest << " == " << edge.weight << "\n";
            mst_weight += edge.weight;
            if (++edge_count == V - 1) break;
        }
    }
    cout << "Minimum Spanning Tree Total Weight: " << mst_weight << "\n";
}

int main() {
    int V = 4;
    vector<Edge> edges = {
        {0, 1, 10}, {0, 2, 6}, {0, 3, 5}, {1, 3, 15}, {2, 3, 4}
    };

    kruskalMST(V, edges);
    return 0;
}
