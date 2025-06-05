#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
    int n, k, u;

    cin >> n >> k >> u;

    vector<set<int>> cartelas(n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            int v;
            cin >> v;
            cartelas[i].insert(v);
        }
    }

    vector<int> bolas(u);
    for (int i = 0; i < u; i++) {
        cin >> bolas[i];
    }

    vector<int> vencedoras;
    for (auto &b : bolas) {
        int j = 1;
        for (auto &c : cartelas) {
            c.erase(b);
            if (c.empty())
                vencedoras.push_back(j);
            j++;
        }
        if (!vencedoras.empty()) break;
    }

    for (auto x : vencedoras) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
