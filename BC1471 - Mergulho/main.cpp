#include <iostream>
#include <vector>

using namespace std;

int main() {

    int n, r;

    while (cin >> n >> r) {
//        cin >> r;

        vector<bool> voltou(n, false);

        int _r = r;

        while (_r--) {
            int p;
            cin >> p;
            voltou[p - 1] = true;
        }

        if (r == n) {
            cout << "*" << endl;
        } else {
            for (int i = 0; i < n; i++) {
                if (!voltou[i])
                    cout << (i + 1) << " ";
            }
            cout << endl;
        }
    }

    return 0;
}
