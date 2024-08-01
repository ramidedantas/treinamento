#include <iostream>
#include <vector>
#include <queue>
#include <deque>

#define MAX  1024

char img[MAX][MAX];
int gsize[MAX][MAX];


std::pair<int, int> parent[MAX][MAX];

using namespace std;

typedef unsigned long long ull;

// Não aceita; runtime error (core dump) -> stack overflow?
void paint_dfs(int n, int m, int i, int j) {
    if (i < 0 || i >= n) return;
    if (j < 0 || j >= m) return;
    if (img[i][j] != '.') return;

    img[i][j] = 'x';

    paint_dfs(n, m, i + 1, j);
    paint_dfs(n, m, i - 1, j);
    paint_dfs(n, m, i, j + 1);
    paint_dfs(n, m, i, j - 1);
}

void enqueue(int n, int m, int i, int j, deque<pair<int, int>> &q) {
    if (i < 0 || i >= n) return;
    if (j < 0 || j >= m) return;
    if (img[i][j] != '.') return;

    q.emplace_back(i, j);
}

// Não aceita; estouro de memória (pq?)
ull paint_bfs(int n, int m, int i, int j) {
    if (i < 0 || i >= n) return 0;
    if (j < 0 || j >= m) return 0;
    if (img[i][j] != '.') return 0;

    ull max_q = 0;

    deque<pair<int, int>> q;
//    q.emplace(i, j);
    q.emplace_back(i, j);

    while (!q.empty()) {
        auto p = q.front();
        q.pop_front();

        int ii = p.first;
        int jj = p.second;

        img[ii][jj] = 'x';

        enqueue(n, m, ii + 1, jj, q);
        enqueue(n, m, ii - 1, jj, q);
        enqueue(n, m, ii, jj + 1, q);
        enqueue(n, m, ii, jj - 1, q);

//        max_q = max(q.gsize(), max_q);
    }

    return max_q;
}

pair<int, int> find(int i, int j) {
    auto p = parent[i][j];
    auto gp = parent[p.first][p.second];
    while (p != gp) {
        p = gp;
        gp = parent[gp.first][gp.second];
    }
    return p;
}

void connect(pair<int, int> p1, pair<int, int> p2) {
    int s1 = gsize[p1.first][p1.second];
    int s2 = gsize[p2.first][p2.second];

    auto big_g = p1, small_g = p2;
    if (s1 < s2)  { big_g = p2; small_g = p1; }

    parent[small_g.first][small_g.second] = big_g;
    gsize[big_g.first][big_g.second] += gsize[small_g.first][small_g.second];
}

// solução aceita: Union-Find
int paint_uf(int n, int m) {

    int di[] = {-1, +1, 0, 0};
    int dj[] = {0, 0, -1, + 1};

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            parent[i][j] = pair(i, j);
            gsize[i][j] = 1;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (img[i][j] == 'o') {
                parent[i][j] = pair(-1, -1);
                continue;
            }

            for (int d = 0; d < 4; d++) {
                int _i = i + di[d];
                int _j = j + dj[d];
                if (_i < 0 || _i >= n) continue;
                if (_j < 0 || _j >= m) continue;
                if (img[_i][_j] == 'o') continue;

                auto p1 = find(i, j);
                auto p2 = find(_i, _j);

                if (p1 != p2) {
                    connect (p1, p2);
                }
            }
        }
    }

    int colors = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (parent[i][j] == pair(i, j)) {
                colors ++;
            }
        }
    }

    return colors;
}

int main() {
    int n, m;

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> img[i][j];
        }
    }

//    int count = 0;
//    ull max_q = 0;

//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < m; j++) {
//            if (img[i][j] == '.') {
//                count ++;
//                ull mq = paint_bfs(n, m, i, j);
////                max_q = max(mq, max_q);
//            }
//        }
//    }

    cout << paint_uf(n, m) << endl;

//    cout << count << endl;
//    cout << max_q << endl;

    return 0;
}
