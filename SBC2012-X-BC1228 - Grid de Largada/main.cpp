#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {

    int n;

    while (cin >> n) {
        vector<int> inicial(n + 1);
        vector<int> final(n + 1);

        for (int i = 0; i < n; i++) cin >> inicial[i];
        for (int i = 0; i < n; i++) cin >> final[i];

        vector<set<int>> na_frente_ini(n + 1);
        vector<set<int>> na_frente_fim(n + 1);


        for (int i = 0; i < n; i++) {
            int pi = inicial[i];
            int pf = final[i];
            for (int j = 0; j < i; j++) {
                na_frente_ini[pi].emplace(inicial[j]);
                na_frente_fim[pf].emplace(final[j]);
            }
        }

        int cont = 0;

        for (int i = 1; i <= n; i++) {
            for (int p : na_frente_ini[i]) {
                if (!na_frente_fim[i].contains(p)) cont++;
            }
        }

        cout << cont << endl;
    }

    return 0;
}
