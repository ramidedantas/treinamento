#include <iostream>

using namespace std;

int main() {
    int n;
    long long p = 0, q = 1; // <<-- atenção

    cin >> n;

    while (n--) q *= 2; // q = 2 ^ N

    q++;                // 2 ^ n + 1

    p = q * q;          // (2 ^ n + 1) ^ 2

    cout << p << endl;

    return 0;
}
