#include <iostream>
#include <vector>
#include <set>

typedef unsigned long long ull;

using namespace std;

int main() {
    int n;

    while (cin >> n) {
        vector<int> vals(n);
        vector<ull> accs(n);
        set<ull> valset;

        ull total_sum = 0;

        for (int i = 0; i < n; i++) {
            cin >> vals[i];
            accs[i] = (i > 0?accs[i - 1]:0) + vals[i];
            valset.insert(accs[i]);
            total_sum += vals[i];
        }

        for (int i = 0; i < n; i++) {
            accs[i] -= vals[i];
        }

        if (total_sum % 3) {
            cout << 0 << endl;
            continue;
        }

        ull side = total_sum / 3;

        int count = 0;

        for (int i = 0; i < n; i++) {
            if (accs[i] >= side) break;

            ull j = (accs[i] + side);

            if (!valset.count(j)) continue;

            ull k = (accs[i] + 2 * side);

            if (!valset.count(k)) continue;

            count++;
        }

        cout << count << endl;
    }

    return 0;
}
