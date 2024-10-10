#include <iostream>

using namespace std;

int main() {

    int n, h;
    int c = 0;

    cin >> n >> h;

    while (n--) {
        int a;
        cin >> a;
        if (a <= h) c++;
    }

    cout << c << endl;

    return 0;
}
