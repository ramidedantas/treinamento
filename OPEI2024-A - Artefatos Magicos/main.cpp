#include <iostream>
#include <set>
#include <vector>

using namespace std;

bool ssk_p(vector<int> &arr, int n, int s, int p, set<int> &res) {
    if (s == 0 && p == 0) return true;

    if (p < 0) return false;

    if (n == 0) return false;

    if (ssk_p(arr, n - 1, s, p, res)) {
        return true;
    }

    if (ssk_p(arr, n - 1, s - arr[n - 1], p - 1, res)) {
        res.insert(arr[n - 1]);
        return true;
    }

    return false;
}

bool ssk_p_memo(vector<int> &arr, int n, int s, int p, set<int> &res,
                vector<vector<vector<int>>> &memo) {
    if (s == 0 && p == 0) return true;

    if (p < 0) return false;

    if (n == 0) return false;

    if (memo[n][s][p] != -1) {
        return memo[n][s][p] == 1;
    }

    if (ssk_p(arr, n - 1, s, p, res)) {
        memo[n][s][p] = 1;
        return true;
    }

    if (ssk_p(arr, n - 1, s - arr[n - 1], p - 1, res)) {
        res.insert(arr[n - 1]);
        memo[n][s][p] = 1;
        return true;
    }

    memo[n][s][p] = 0;
    return false;
}

int main() {

    int s, p, n;

    cin >> s >> p >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    set<int> res;

    vector<vector<vector<int>>> memo(n + 1,
                                      vector<vector<int>>(s + 1,
                                              vector<int>(p+1, -1)));

    if (ssk_p_memo(arr, n, s, p, res, memo)) {
        for (int v : res) {
            cout << v << endl;
        }
    } else {
        cout << -1 << endl;
    }

    return 0;
}
