#include <iostream>

using namespace std;

int main() {

    int n;

    cin >> n;

    int f0, f1, f2, f3;

    f0 = (n - 2) * (n - 2) * (n - 2);

    f1 = 6 * (n - 2) * (n - 2);

    f2 = 12 * (n - 2);

    f3 = 8;

    cout << f0 << endl;
    cout << f1 << endl;
    cout << f2 << endl;
    cout << f3 << endl;

    return 0;
}
