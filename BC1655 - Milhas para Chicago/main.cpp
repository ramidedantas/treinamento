#include <iostream>
#include <list>
#include <vector>
#include <set>
#include <iomanip>

using namespace std;

// Dijkstra usando set como pq
// Ajustado nesse problema para maximizar probibilidade, em vez de minimizar distância
void dijkstra2(const vector<list<pair<int, double>>> &graph, int s, vector<int> &prev, vector<double> &prob) {
    set<pair<int, double>> pq;

    prob[s] = 1.0;
    pq.emplace(s, prob[s]);

    while (!pq.empty()) {
        // maior probabilidade
        int curr = std::prev(pq.end())->first;
        double p_acc = std::prev(pq.end())->second;

        pq.erase(std::prev(pq.end()));

        auto & adj = graph[curr];

        for ( auto & [v, p] : adj) {
            if (prob[v] < (p_acc * p)) {
                pq.erase(make_pair(v, prob[v]));
                prob[v] = p_acc * p;
                prev[v] = curr;
                pq.emplace(v, prob[v]);
            }
        }
    }
}

int main() {

    while (true) {
        int n, m;

        cin >> n;

        if (n == 0) return 0;

        cin >> m;

        vector<list<pair<int, double>>> graph(n + 1);

        for (int i = 0; i < m; i++) {
            int a, b;
            double p;

            cin >> a >> b >> p;

            graph[a].emplace_back(b, (double)p / 100);
            graph[b].emplace_back(a, (double)p / 100);
        }

        vector<int> prev(n + 1, -1);
        vector<double> prob(n + 1, 0);

        dijkstra2(graph, 1, prev, prob);

        cout << std::setprecision(6) << std::fixed << 100 * prob[n] << " percent" << endl;
    }
}
