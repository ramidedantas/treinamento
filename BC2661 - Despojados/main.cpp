#include <iostream>
#include <vector>
#include <valarray>
#include <set>

using namespace std;

typedef unsigned long long ull;

// Na apostila!
vector<ull> factors(ull n) {
    vector<ull> f;
    for (int x = 2; x*x <= n; x++) {
        while (n%x == 0) {
            f.push_back(x);
            n /= x;
        }
    }
    if (n > 1) f.push_back(n);
    return f;
}


int main() {
    ull n;
    set<ull> primos;

    cin >> n;

    // Pegando fatores primos (pode ter repetição)
    auto fatores = factors(n);

    // Inserindo fatores num set para contar fatores únicos
    primos.insert(fatores.begin(), fatores.end());

    int m = primos.size();

    // (1L << m) = 2^m
    cout << ((1L << m) - m - 1) << endl;

    return 0;
}
