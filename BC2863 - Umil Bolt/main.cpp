
// Beecrowd 2863 Umil Bolt

#include <iostream>

using namespace std;

int main() {

    int n;
    while (cin >> n) {
        float v, min = 10000;
        for (int i = 0; i < n; i++) {
            cin >> v;
            if (v < min) min = v;
        }

        cout << min << endl;
    }

    return 0;
}