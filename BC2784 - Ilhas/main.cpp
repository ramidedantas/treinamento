#include <iostream>
#include <list>
#include <vector>
#include <queue>
#include <climits>
#include <set>

#define INF LONG_MAX

using namespace std;

bool operator < (const pair<int, int> &a, const pair<int, int> &b) {
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

        auto & adj = graph[curr];

        for ( auto & [v, d] : adj) {
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

        auto & adj = graph[curr];

        for ( auto & [v, d] : adj) {
            if (dist[v] > (d_acc + d)) {
                pq.erase(make_pair(v, dist[v]));
                dist[v] = d_acc + d;
                prev[v] = curr;
                pq.emplace(v, dist[v]);
            }
        }
    }
}

int main() {

    int n, m, s;

    cin >> n >> m;

    vector<list<pair<int, int>>> graph(n + 1);

    for (int i = 0; i < m; i++) {
        int u, v, p;
        cin >> u >> v >> p;

        graph[u].emplace_back(v, p); // = graph[u].push_back(make_pair(v, p));
        graph[v].emplace_back(u, p);
    }

    cin >> s;

//    for (int i = 1; i <= n; i++) {
//        cout << i << ": ";
//        for (auto [v, p] : graph[i]) {
//            cout << v << "(" << p << ") ";
//        }
//        cout << endl;
//    }

    vector<int> prev(n + 1, -1);
    vector<long> ping(n + 1, INF);

    dijkstra2(graph, s, prev, ping);

//    for (int i = 1; i <= n; i++) {
//        cout << "ping[" << i << "] = " << ping[i] << endl;
//    }

    long min_ping = LONG_MAX, max_ping = LONG_MIN;

    for (int i = 1; i <= n; i++) {
        if (i == s) continue;
        min_ping = min(min_ping, ping[i]);
        max_ping = max(max_ping, ping[i]);
    }

    cout << max_ping - min_ping << endl;

    return 0;
}
