//
// Maratona Fase Zero 2023
// Tempo limite: 5 segs (O(N^2) ok?)

#include <iostream>
#include <algorithm>

using namespace std;


int my_binsearch(const int *a, int n, int v) {
    int ini = 0, end = n - 1;
    int m = (ini + end) / 2;

    while (ini <= end && a[m] != v) {
        if (a[m] < v) ini = m + 1;
        else end = m - 1;
        m = (ini + end) / 2;
    }

    return (a[m] == v)?m:-1;
}

void my_remove(int *a, int n, int idx) {
    for (int i = idx; i < n - 1; i++) {
        a[i] = a[i + 1];
    }
}

void print(int *a, int n) {
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

bool match(int *g, int *e, int n, int c) { // O(N^2)?
    int e_n = n;
    int e_c[n];
    memcpy(e_c, e, n * sizeof (int));
    for (int i = 0; i < n; i++) { // O(N...)
        int err = abs(c - g[i]);
        int idx = my_binsearch(e_c, e_n, err); // O(logN)
        if (idx == -1) return false;
        my_remove(e_c, e_n, idx); // O(N)
        e_n--;
    }
    return true;
}

//int main() {
int main_ok() {
    int n;

    cin >> n;

    int g[n];
    int e[n];

    for (int i = 0; i < n; i++) {
        cin >> g[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> e[i];
    }

    sort(g, g + n);
    sort(e, e + n);

    int max_e = e[n-1];

    int c1 = g[0] - max_e, c2 = g[0] + max_e;

    for (int i = 1; i < n; i++) {
        c1 = max(c1, g[i] - max_e);
        c2 = min(c2, g[i] + max_e);
    }

    if ((c1 > 0) && (c1 < 1000000000) && match(g, e, n, c1)) {
        cout << c1 << endl;
    }

    if ((c2 != c1) && (c2 > 0) && (c2 < 1000000000) && match(g, e, n, c2)) {
        cout << c2 << endl;
    }

    return 0;
}
