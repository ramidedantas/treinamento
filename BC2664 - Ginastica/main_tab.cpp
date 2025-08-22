
#include <iostream>
#include <vector>

#define M (1000000007LL)

using namespace std;

typedef unsigned long long ull;

int main() {
    int t, m, n;

    cin >> t >> m >> n;

    ull levels = n - m + 1;

    vector<ull> cur(levels, 1), next(levels);

    while (--t) {
        next[0] = cur[1];
        next[levels - 1] = cur[levels - 2];
        for (int i = 1; i < levels - 1; i++) {
            next[i] = (cur[i - 1] + cur[i + 1]) % M;
        }
        cur = next;
    }

    ull ans = 0;
    for (auto v : cur) {
        ans = (ans + v) % M;
    }
    cout << ans << endl;

//    ull ans = levels;
//    while (--t) {
//        ans = ((((ans - 2) % M) * 2) % M + 2) % M;
//    }
//    cout << ans << endl;

    return 0;
}