#include <iostream>

typedef unsigned long long ull;

using namespace std;

ull calc(ull n, ull r) {
    return 4 * (r*r + r * (n - 2*r));
}

int main() {

    ull n, b;

    cin >> n >> b;

    ull r = 1;

    while ((2*r < n) && calc(n, r) <= b) r *= 2;

    r /= 2;

    while ((2*r < n) && calc(n, r) <= b) r++;

    r--;

    b -= calc(n, r);

    ull l, c;

    if (b == 0) { // X
        l = r + 1;
        c = r;
    } if (b <= n - 2 * r) { // A
        l = r + 1;
        c = b + r;
    } else {
        b -= n - 2 * r;
        if (b <= (n - 2 * r - 1)) { // B
            l = r + b + 1;
            c = n - r;
        } else {
            b -= (n - 2 * r - 1);
            if (b <= (n - 2 * r - 1)) { // C
                l = n - r;
                c = n - (b + r);
            } else { // D
                b -= (n - 2 * r - 1);
                l = n - (b + r);
                c = r + 1;
            }
        }
    }

    cout << l << " " << c << endl;

    return 0;
}
