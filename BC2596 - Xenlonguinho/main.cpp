#include <iostream>
#include <vector>
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

int main() {
    int c;
    cin >> c;

    vector<int> divs(MAX + 1, 0);

    init(divs); // O(K)

    while (c--) {
        int n;
        cin >> n;

        int impares = 0;
        for (int i = 1; i <= n; i++) { // O(n)
            if (divs[i] % 2) impares++;
        }

        cout << n - impares << endl;
    }
    return 0;
}
