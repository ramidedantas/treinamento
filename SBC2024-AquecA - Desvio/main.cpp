/* Beecrowd 2784 - Ilhas*/
#include <iostream>
#include <list>
#include <vector>
#include <queue>
#include <climits>
#include <set>
#include <algorithm>

#define INF LONG_MAX

using namespace std;

bool operator<(const pair<int, int> &a, const pair<int, int> &b) {
    return a.second < b.second;
}

void dijkstra(const vector<list<pair<int, int>>> &graph, int s, vector<int> &prev, vector<long> &dist) {
    priority_queue<pair<int, long>> pq;


    dist[s] = 0;
    pq.emplace(s, dist[s]);


    while (!pq.empty()) {
        int curr = pq.top().first;
        long d_acc = pq.top().second;
        pq.pop();


        auto &adj = graph[curr];


        for (auto &[v, d]: adj) {
            if (dist[v] > (d_acc + d)) {
                dist[v] = d_acc + d;
                prev[v] = curr;
                pq.emplace(v, dist[v]);
            }
        }
    }
}


void dijkstra2(const vector<list<pair<int, int>>> &graph, int s, vector<int> &prev, vector<long> &dist) {
    set<pair<int, long>> pq;


    dist[s] = 0;
    pq.emplace(s, dist[s]);


    while (!pq.empty()) {
        int curr = pq.begin()->first;
        long d_acc = pq.begin()->second;
        pq.erase(pq.begin());


        auto &adj = graph[curr];


        for (auto &[v, d]: adj) {
            if (dist[v] > (d_acc + d)) {
                pq.erase(make_pair(v, dist[v]));
                dist[v] = d_acc + d;
                prev[v] = curr;
                pq.emplace(v, dist[v]);
            }
        }
    }
}

struct edge {
    int u, v, l;
};

int main() {
    int n, m, s;

    cin >> n >> m;

    vector<list<pair<int, int>>> graph(n + 1);
    vector<edge> edges(m);

    for (int i = 0; i < m; i++) {
        int u, v, l;
        cin >> u >> v >> l;

        edges[i] = edge {u, v, l};
        graph[u].emplace_back(v, l);
        graph[v].emplace_back(u, l);
    }

//    for (int k = 1; k <= n; k++) {
//        cout << k << ": ";
//        for ( auto t : graph[k]) {
//            cout << "(" << t.first << ": " << t.second << ") ";
//        }
//        cout << endl;
//    }

    for (int i = 0; i < m; i++) {
        edge e = edges[i];
        vector<list<pair<int, int>>> copy = graph;

        copy[e.v].erase(std::find(copy[e.v].begin(), copy[e.v].end(), make_pair(e.u, e.l)));
        copy[e.u].erase(std::find(copy[e.u].begin(), copy[e.u].end(), make_pair(e.v, e.l)));

//        for (int k = 1; k <= n; k++) {
//            cout << k << ": ";
//            for ( auto t : copy[k]) {
//                cout << "(" << t.first << ": " << t.second << ") ";
//            }
//            cout << endl;
//        }

        vector<int> prev(n + 1, -1);
        vector<long> dist(n + 1, INF);

        dijkstra2(copy, e.u, prev, dist);

        if (dist[e.v] == INF) cout << -1 << endl;
        else cout << dist[e.v] << endl;
    }

    return 0;
}
