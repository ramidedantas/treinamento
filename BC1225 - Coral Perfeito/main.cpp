#include <iostream>
#include <vector>

using namespace std;

typedef unsigned long long ull;

int main() {
    int n;

    while (cin >> n) {
        ull total = 0;

        vector<int> vals(n);

        for (int i = 0; i < n; i++) {
            cin >> vals[i];
            total += vals[i];
        }

        if (total % n) {
            cout << -1 << endl;
            continue;
        }

        ull target = total / n;
        ull res = 0;

        for (int i = 0; i < n; i++) {
            if (vals[i] < target)
                res += target - vals[i];
        }

        cout << res + 1 << endl;
    }

    return 0;
}
