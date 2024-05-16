#include <iostream>

using namespace std;

// Solução aceita
// Duplo tratamento especial:
//   - K = 0: seqs = combinações de vários tamanhos
//   - K > 0: vetor de prefixos zero -> sequências adicionais
// Complexidade estimada: O(N)
// Similar a solução oficial

#define MAX_N 500000
#define MAX_K 1000000
#define MAX_X 100

typedef long long ull;

void print(ull * a, ull n, const char * msg) {
    cout << msg;
    for (ull i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main_iter() {
//int main() {

    ull n, k;

    cin >> n >> k;

    ull a[n];
    ull count[n];
    ull ini[n];
    ull sum[n];
    ull zeros[n];
    ull sorez[n];

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        count[i] = sum[i] = zeros[i] = 0;
        ini[i] = -1;
    }
    sorez[n - 1] = (a[n - 1] == 0);
    for (ull i = (n - 2); i >= 0; i--) {
        sorez[i] = (a[i] == 0)?sorez[i + 1] + 1:0;
    }

    zeros[0] = sorez[0];
    ini[0] = 0;
    sum[0] = a[0];

    if (k > 0) {

        for (int i = 1; i < n; i++) { // O(N) ou O(N^2) ?
            ini[i] = ini[i - 1];
            sum[i] = sum[i - 1] + a[i];
            zeros[i] = sorez[ini[i]];
            while (sum[i] > k && ini[i] < i) {
                sum[i] -= a[ini[i]];
                ini[i]++;
                zeros[i] = sorez[ini[i]];
            }
        }

        for (int i = 0; i < n; i++) { // O(N)
            count[i] = (sum[i] == k) ? zeros[i] + 1 : 0;
        }
    } else {
        for (int i = 0; i < n; i++) {
            count[i] = sorez[i];
        }
    }

    ull total = 0;
    for (int i = 0; i < n; i++) {
        total += count[i];
    }

    cout << total << endl;
//
//    print(a,       n, "array: ");
//    print(count, n, "count: ");
//    print(sum,   n, "sum:   ");
//    print(ini,   n, "ini:   ");
//    print(zeros, n, "zeros: ");
//    print(sorez, n, "sorez: ");

    return 0;
}
