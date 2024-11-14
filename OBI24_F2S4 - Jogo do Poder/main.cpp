#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

typedef unsigned long long ull;

#define PUSH(x, y) if ((x) >= 0 && (x) < n && (y) >= 0 && (y) < m && !visitado[x][y]) { q.emplace((x),(y)); visitado[x][y] = true; }

#define PUSH2(x, y) if ((x) >= 0 && (x) < n && (y) >= 0 && (y) < m && !visitado[x][y]) { \
                        q.emplace((x),(y), jogo[x][y]); \
                        visitado[x][y] = true; \
                    }

ull bfs(const vector<vector<ull>> &jogo, int n, int m, int i, int j) {
    vector<vector<bool>> visitado(n, vector<bool>(m, false));
    queue<pair<int, int>> q;

    ull poder = 0;
    q.emplace(i, j);
    visitado[i][j] = true;

    int maior = 0;
    while (!q.empty() && (maior < q.size())) {
        auto v = q.front();
        if (poder == 0 || jogo[v.first][v.second] <= poder) {
            poder += jogo[v.first][v.second];
            q.pop();
            maior = 0;

            i = v.first; j = v.second;

            PUSH(i, j + 1);
            PUSH(i, j - 1);
            PUSH(i + 1, j);
            PUSH(i - 1, j);
        } else {
            maior++;
            q.push(q.front());
            q.pop();
        }
    }

    return poder;
}

struct posicao {
    int i, j;
    ull poder;
    posicao(int i, int j, ull poder) : i(i), j(j), poder(poder) { }
    bool operator <(const posicao &p) const {
        if (poder == p.poder)
            return (i < p.i) || (j < p.j);
        return poder < p.poder;
    }
};

ull bfs2(const vector<vector<ull>> &jogo, int n, int m, int i, int j) {
    vector<vector<bool>> visitado(n, vector<bool>(m, false));
    set<posicao> q;

    ull poder = 0;
    q.emplace(i, j, jogo[i][j]);
    visitado[i][j] = true;

    while (!q.empty() && q.begin()->poder <= poder || poder == 0) {
        auto v = *q.begin();
        q.erase(q.begin());

        poder += v.poder;

        PUSH2(v.i, v.j + 1);
        PUSH2(v.i, v.j - 1);
        PUSH2(v.i + 1, v.j);
        PUSH2(v.i - 1, v.j);
    }

    return poder;
}

int main() {

    int n, m;

    cin >> n >> m;

    vector<vector<ull>> jogo(n, vector<ull>(m));

    vector<vector<ull>> res(n, vector<ull>(m, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> jogo[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            res[i][j] = bfs2(jogo, n, m, i, j);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
