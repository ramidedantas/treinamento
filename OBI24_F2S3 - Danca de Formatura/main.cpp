#include <iostream>
#include <vector>

using namespace std;

int main() {

    int n, m, p;

    cin >> n >> m >> p;

    vector<vector<int>> danca(n, vector<int>(m));

    int c = 1;
    for (auto &linha : danca) {
        for (auto &v : linha) {
            v = c++;
        }
    }

    while (p--) {
        char op;
        int a, b;

        cin >> op >> a >> b;

        a--; b--;

        if (op == 'C') { // coluna
            for (int i = 0; i < n; i++) {
                swap(danca[i][a], danca[i][b]);
            }
        } else { // linha
            swap(danca[a], danca[b]);
        }
    }

    for (auto &linha : danca) {
        for (auto v : linha) {
            cout << v << " ";
        }
        cout << endl;
    }

    return 0;
}
