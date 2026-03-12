#include <iostream>

using namespace std;

typedef unsigned long long ull;

int main() {
    ull a, b, n, sum = 0;

    cin >> a >> b; // C++

    for (ull i = a; i <= b; i++) {
        sum += i;
    }

    cout << sum << endl; // C++

    return 0;
}