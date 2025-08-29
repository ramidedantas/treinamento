#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int min_blocos(const vector<int> &a, int m) {
    int res = INT_MAX;

    vector<int> mb(m + 1, -1);
    mb[0] = 0;
    for (int i = 1; i <= m; i++) {
        int v = INT_MAX;
        for (int b : a) {
            if (b > i) continue;
            if (mb[i - b] < 0) continue;
            v = min(v, mb[i - b] + 1);
        }
        mb[i] = v;
    }

    return mb[m];
}

int main() {

    int t;

    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        int res = min_blocos(a, m);

        cout << res << endl;
    }

    return 0;
}
