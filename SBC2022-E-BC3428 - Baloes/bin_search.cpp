#include <iostream>
#include <vector>
#include <map>

using namespace std;

// O(N^2)
bool test(vector<int> B, int arrows) {
    int popped = 0;
    int i = -1, n = (int)B.size();
    while (arrows--) {
        int a;
        while (i < n && !B[++i] );
        if (i >= n) break;
        a = B[i] - 1; B[i] = 0; popped++;
        for (int j = i; j < n; j++) {
            if (a <= 0) break;
            if (B[j] == a) {
                B[j] = 0;
                popped++;
                a--;
            }
        }
    }
    return popped == n;
}

int main() {
    int n;

    // input
    cin >> n;
    vector<int> B(n);
    auto Bi = B.begin();
    while (Bi != B.end()) { cin >> *Bi++; }

    // O(N^2logN)
    int ini = 1, end = n, mid, succ = -1;
    while (ini <= end) { // O(logN)
        mid = (ini + end) / 2;
        if (test(B, mid)) { // O(N^2)
            succ = mid;
            end = mid - 1;
        } else {
            ini = mid + 1;
        }
    }

    cout << succ << endl;

    return 0;
}

