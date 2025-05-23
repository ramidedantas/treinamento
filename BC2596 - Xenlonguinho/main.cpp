#include <iostream>
#include <vector>
#include <valarray>

#define MAX 1000

using namespace std;

void init(vector<int> &divs) {
    for (int i = 1; i <= MAX; i++) {
        int k = 0;
        while (k < MAX) {
            divs[k]++;
            k += i;
        }
    }
}

void init2(vector<int> &even_divs) {
    vector<bool> has_even_divs(MAX + 1, true);

    int lim = (int)sqrt(MAX);
    for (int v = 1; v <= lim; v++) {
        has_even_divs[v*v] = false;
    }

    int even_div = 0;
    for (int i = 1; i <= MAX; i++) {
        if (has_even_divs[i]) even_div++;
        even_divs[i] = even_div;
    }
}

int main() {
    int c;
    cin >> c;

//    vector<int> divs(MAX + 1, 0);
//    init(divs); // O(K)

    vector<int> even_divs(MAX + 1, 0);
    init2(even_divs);

    while (c--) {
        int n;
        cin >> n;

//        int impares = 0;
//        for (int i = 1; i <= n; i++) { // O(n)
//            if (divs[i] % 2) impares++;
//        }
//
//        cout << n - impares << endl;

        cout << even_divs[n] << endl;
    }
    return 0;
}
