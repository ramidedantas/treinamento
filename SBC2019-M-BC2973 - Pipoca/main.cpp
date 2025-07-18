#include <iostream>
#include <vector>

using namespace std;

bool try_time(vector<int> &p, int c, int t, int time) {
    int j = 0;
    for (int i = 0; i < c; i++) {
        int s = 0;
        while (j < p.size() && (s + p[j] + t - 1)/t <= time) { // arredondamento?
            s += p[j++];
        }
    }

    return j == p.size();
}

int main() {

    int n, c, t;

    cin >> n >> c >> t;

    vector<int> p(n);
    int total = 0;

    for (int i = 0; i < n; i++) {
        cin >> p[i];
        total += p[i];
    }

    int max_time = (total + t - 1) / t;

    int ini = 0, end = max_time, mid, succ = -1;

    while (ini <= end) {
        mid = (ini + end) / 2;

        if (try_time(p, c, t, mid)) {
            succ = mid;
            end = mid - 1;
        } else {
            ini = mid + 1;
        }
    }

    cout << succ << endl;
    return 0;
}
