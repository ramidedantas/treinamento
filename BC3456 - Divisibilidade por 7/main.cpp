#include <iostream>

using namespace std;

int main() {
    unsigned long long n; // <-- atenção: 0 <= n <= 10^15.

    cin >> n;

    while ((n / 10) > 0) {
        cout << n << endl;

        n = (n / 10) * 3 + (n % 10);
    }
    cout << n << endl;

    return 0;
}
