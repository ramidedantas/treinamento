#include <iostream>

// Solução em força bruta, O(N^2)
// Não passa por estourar o tempo.

using namespace std;

typedef unsigned long long ull;

int main_bf() {
//int main() {
    ull n, k;

    cin >> n >> k;

    ull a[n];

    for (ull i = 0; i < n; i++) {
        cin >> a[i];
    }

    ull sum = 0, count = 0;

    for (ull len = 1; len <= n; len++) {
        sum = 0;
        for (ull j = 0; j < len; j++) {
            sum += a[j];
        }
        ull head = 0;
        for (ull shift = 0; shift < n - (len - 1); shift++) {
            if (sum == k) count++;
//            cout << "[sum = " << sum << "] ";
//            for (ull i = 0; i < len; i++) {
//                cout << a[head + i] << " ";
//            }
//            cout << endl;

            sum -= a[head++];
            sum += a[head + (len - 1)];
        }
    }

    cout << count << endl;

    return 0;
}
