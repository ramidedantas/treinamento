#include <iostream>

using namespace std;

int main() {
    int m, n, a, b;

    while (cin >> m >> n && m && n) {
        // cin >> m >> n;
        //
        // if (m == 0 || n == 0) break;

        char img[m][n];

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cin >> img[i][j];
            }
        }

        cin >> a >> b;

        for (int i = 0; i < a; i++) {
            int x = i / (a / m);
            for (int j = 0; j < b; j++) {
                int y = j / (b / n);
                cout << img[x][y];
            }
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}
