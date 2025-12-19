#include <iomanip>
#include <iostream>

using namespace std;

int main() {

    int n;

    cin >> n;

    while (n) {
        long long max = 1 << (n * 2 - 2);
        string str = to_string(max);
        auto len = str.length();

        long long x = 1;
        for (int i = 0; i < n; i++) {
            long long y = x;
            for (int j = 0; j < n; j++) {
                cout << setw(len) << y;
                if (j < n - 1) cout << " ";
                y *= 2;
            }
            cout << endl;
            x *= 2;
        }
        cout << endl;
        cin >> n;
    }

    return 0;
}
