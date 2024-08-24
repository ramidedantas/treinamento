#include <iostream>
#include <vector>

using namespace std;

typedef unsigned long long ull;

vector<ull> fat(10000, 0);

ull fatorial(ull n) {
    if (n == 1) return 1;
    if (fat[n] > 0) return fat[n];
    return fat[n] = n * fatorial(n - 1);
}

ull big_fat(ull k) {
    ull bf = 1;
    for (ull v = 1; v <= k; v++) {
        ull f = fatorial(v);
        if (f > k) return bf;
        bf = f;
    }
    return bf;
}

int main() {

    ull n;

    cin >> n;

    int c = 0;
    while (n) {
        n -= big_fat(n);
        c++;
    }

    cout << c << endl;

    return 0;
}
