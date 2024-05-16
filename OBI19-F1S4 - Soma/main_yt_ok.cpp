#include <iostream>

// Solução do Youtube
// https://www.youtube.com/watch?v=qtHjRi_HC5Q
//
// Aceita 100%
// Complexidade estimada: O(NlogN) [ logN da busca binária ]

using namespace std;

#define MAX_N 500000

typedef long long ull;

ull n, k, x;
ull v[MAX_N + 1], a[MAX_N + 1];
ull resp;

ull buscab(ull u) {
    ull ini = u, fim = n, meio, ret = -1;
    while (ini <= fim) {
       meio = (ini + fim) / 2;
       if (v[meio] - v[u - 1] == k) {
           ret = meio;
           ini = meio+1;
       } else if (v[meio] - v[u - 1] > k) fim = meio - 1;
       else ini = meio + 1;
    }
    return ret;
}

//int main_yt() {
int main() {

    cin >> n >> k;

    for (ull  i = 0; i < n; i++) {
        cin >> x;
        v[i+1] = v[i] + x;

        if (v[i+1] == v[i]) {
            a[i+1] = a[i];
        } else a[i+1] = i+1;
    }

    for (ull i = 1; i <= n; i++) {
        ull temp = buscab(i);

        if (temp != -1) {
            resp += temp - max(i, a[temp]) + 1;
        }
    }

    cout << resp << endl;

    return 0;
}
