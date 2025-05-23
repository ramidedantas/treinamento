#include <iostream>

using namespace std;

typedef unsigned long long ull;

ull mdc(ull a, ull b) {
    if (b > a) swap(a, b);
    if (b == 0) return a;
    return mdc(b, a % b);
}

ull mmc(ull a, ull b) {
   return (a * b) / mdc(a, b);
}

int main() {

    ull n, a, b;

    while (true) {
        cin >> n >> a >> b;

        if (a == 0) break;

        ull _mmc = mmc(a, b);

        ull c = (n / a) + (n / b) - (n / _mmc);

        cout << c << endl;
    }

    return 0;
}
