#include <iostream>
#include <list>
#include <vector>

using namespace std;

// DFS = Depth-First Search
// Atravesa o grafo em profundidade contando o número de arestas atravesadas (count)
// Grafo = edges (vetor de listas indexado pelo vértice)
void dfs(const vector<list<int>> &edges, int start, vector<bool> &visited, int & count) {
    if (visited[start]) return;

    visited[start] = true;

    for (auto edge : edges[start]) {
        if (visited[edge]) continue;
        dfs(edges, edge, visited, count);
        count ++;
    }
}

int main() {
    int t;

    cin >> t;

    while (t--) {

        int n, v, a;

        cin >> n >> v >> a;

        vector<bool> visited(v);
        vector<list<int>> edges(v);

        while (a--) {
            int x, y;

            cin >> x >> y;

            edges[x].push_back(y);
            edges[y].push_back(x);
        }

        int count = 0;

        dfs(edges, n, visited, count);

        cout << count * 2 << endl;
    }

    return 0;
}
