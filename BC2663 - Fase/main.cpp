#include <iostream>
#include <vector>

using namespace std;


int main() {
    int n, k;

    cin >> n >> k;

    vector<int> pontos(1001, 0);

    int max_p = -1;

    for (int i = 0; i < n; i++) {
        int p;
        cin >> p;
        pontos[p]++;
        max_p = max(max_p, p);
    }

    int c = 0;
    for (int i = max_p; (i > 0) && (c < k); i--) {
        c += pontos[i];
    }

    cout << c << endl;

    return 0;
}
