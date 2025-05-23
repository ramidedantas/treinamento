#include <iostream>
#include <cmath>

typedef unsigned long long ull;

using namespace std;

ull niveis(ull C) {
    ull N = (ull)floor(sqrt(1 + 24 * (double)C) - 1)/6;
//    ull N = (ull)floor((sqrt(1/C + 24)*sqrt(C) - 1))/6;
    return N;
}

int main() {
    int n;

    cin >> n;

    while (n--) {
        ull c;
        cin >> c;

        cout << niveis(c) << endl;
    }

    return 0;
}
