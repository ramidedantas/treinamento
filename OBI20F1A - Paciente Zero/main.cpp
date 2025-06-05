#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, c;

    cin >> n >> c;

    vector<int> pacientes(n + 1, 0);

    while (c--) {
        int p, i ,x;
        cin >> p >> i;
        for (int j = 0; j < i; j++) {
            cin >> x;
            pacientes[x] = p;
        }
    }

    for (int i = 1; i <= n; i++) {
        if (pacientes[i] == 0) {
            cout << i << endl;
        }
    }

    return 0;
}
