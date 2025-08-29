#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int motoboy(const vector<int> &t, const vector<int> &k, int p) {
//    int memo[t.size() + 1][p + 1];
    vector<vector<int>> memo(t.size() + 1, vector<int>(p + 1, -1));

    for (int c = 0; c <= p; c++) memo[0][c] = 0; // sem pedidos, max = 0
    for (int r = 0; r <= t.size(); r++) memo[r][0] = 0; // P = 0, max = 0

//    cout << endl;
//    for (int r = 0; r <= t.size(); r++) {
//        for (int c = 0; c <= p; c++) {
//            cout << std::setw(3) << memo[r][c] << " ";
//        }
//        cout << endl;
//    }

    for (int r = 1; r <= t.size(); r++) {
        for (int c = 1; c <= p; c++) {
            if (k[r - 1] > c) {
                memo[r][c] = memo[r - 1][c];
            } else {
                memo[r][c] = max(memo[r - 1][c],
                                 memo[r - 1][c - k[r - 1]] + t[r - 1]);
            }
        }
    }

//    cout << endl;
//    for (int r = 0; r <= t.size(); r++) {
//        for (int c = 0; c <= p; c++) {
//            cout << std::setw(3) << memo[r][c] << " ";
//        }
//        cout << endl;
//    }

    return memo[t.size()][p];
}


int main() {
    int n, p;

    cin >> n;
    while (n) {
        cin >> p;
        vector<int> t(n + 1), k(n + 1);
        for (int i = 0; i < n; i++) cin >> t[i] >> k[i];

        int res = motoboy(t, k, p);

        cout << res << " min." << endl;

        cin >> n;
    }

    return 0;
}

