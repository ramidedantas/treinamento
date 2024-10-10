#include <iostream>
#include <vector>
#include <list>

using namespace std;

bool ssk(const vector<int> &a, int n, int k, vector<bool> &res) {

    bool m[n + 1][k + 1];

    for (int i = 0; i <= n; i++) {
        m[i][0] = true;
        for (int j = 1; j <= k; j++) {
            m[i][j] = false;
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j ++) {
            bool p1 = m[i - 1][j];
            bool p2 = (j - a[i - 1] >= 0) && m[i - 1][j - a[i - 1]];
            m[i][j] = p1 || p2;
        }
    }

    if (!m[n][k]) return false;

    int _k = k;
    for (int i = n; i > 0; i--) {
        if ((i - 1 >= 0) && (_k - a[i - 1] >= 0) && m[i - 1][_k - a[i - 1]]) {
            res[i - 1] = true;
            _k -= a[i - 1];
        }
    }

    return true;
}

int main() {
    int n;

    cin >> n;

    vector<int> a(n, 0);
    int sum  = 0;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }

    if (sum % 2) {
        cout << -1 << endl;
        return 0;
    }

    vector<bool> res(n);
    bool possible = ssk(a, n, sum / 2, res);

    if (!possible) {
        cout << -1 << endl;
        return 0;
    }

    list<int> alice, bob;

    for (int i = 0; i < n; i++) {
        if (res[i]) alice.push_back(a[i]);
        else bob.push_back(a[i]);
    }

    int sum_a = 0, sum_b = 0;

    for (int i = 0; i < n; i++) {
        if (sum_a > sum_b) {
            sum_b += bob.front();
            cout << bob.front() << " ";
            bob.pop_front();
        } else {
            sum_a += alice.front();
            cout << alice.front() << " ";
            alice.pop_front();
        }
    }

    return 0;
}
