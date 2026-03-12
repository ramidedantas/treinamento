#include <iostream>

using namespace std;

int main() {
    int n;

    cin >> n;

    n++;

    int M[n][n];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> M[i][j];
        }
    }

    for (int i = 0; i < (n - 1); i++) {
        for (int j = 0; j < (n - 1); j++) {
            int cont = M[i][j] + M[i + 1][j] + M[i][j + 1] + M[i + 1][j + 1];
            cout << (cont >= 2?'S':'U');
        }
        cout << endl;
    }

    return 0;
}