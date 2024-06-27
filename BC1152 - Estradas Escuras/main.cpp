#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

// aresta; w = custo, distância, peso
struct edge {
    int v1, v2, w;
    bool operator < (const edge &e) const { // Necessário para ordenar (sort)
        return w < e.w;
    }
};

int find(vector<int> &parent, int v) {
    int p = parent[v];
    int gp = parent[p];
    while (p != gp) {
        p = gp;
        gp = parent[gp];
    }
    return p;
}

void connect(vector<int> &parent, vector<int> &size, int v1, int v2) {
    int p1 = find(parent, v1);
    int p2 = find(parent, v2);
    int s1 = size[p1];
    int s2 = size[p2];

    int big_g = p1, small_g = p2;
    if (s1 < s2)  { big_g = p2; small_g = p1; }

    parent[small_g] = big_g;
    size[big_g] += size[small_g];
}

// Minimum Spanning Tree - Árvore de Cobertura Mínima
// Algoritmo de Kruskal + Union-Find
void mst_kruskal(vector<edge> &edges, int m, list<edge> &mst_edges) {

    sort(edges.begin(), edges.end()); // O(NlogN)

    vector<int> parent(m), size(m);
    for (int i = 0; i < m; i++) {
        parent[i] = i;
        size[i] = 1;
    }

    for (const auto & edge : edges) { 
        if (find(parent, edge.v1) != find(parent, edge.v2)) { // find
            connect(parent, size, edge.v1, edge.v2); // union
            mst_edges.push_back(edge);
        }
    }
}

int main() {

    while (true) {
        int m, n;
        int x, y, z;

        cin >> m >> n;

        if (m == 0) return 0;

        vector<edge> edges(n);

        while (n--) {
            cin >> x >> y >> z;
            edges.push_back(edge{x, y, z});
        }

        long total_cost = 0;
        for (auto edge : edges)
            total_cost += edge.w;

        list<edge> mst_edges;

        mst_kruskal(edges, m, mst_edges);

        long mst_cost = 0;
        for (auto edge : mst_edges)
            mst_cost += edge.w;

        cout << total_cost - mst_cost << endl;

    }

    return -1;
}
