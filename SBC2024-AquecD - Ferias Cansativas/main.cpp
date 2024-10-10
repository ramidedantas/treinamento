#include <iostream>

using namespace std;

int main() {

    int d, c, r;

    cin >> d >> c >> r;

    int C[c], R[r];

    for (int i = 0; i < c;i++)  cin >> C[i];
    for (int i = 0; i < r;i++)  { cin >> R[i]; d+= R[i]; }

    int count = r;

    for (int i = 0; i < c; i++) {
        if (C[i] <= d) {
            count++;
            d -= C[i];
        } else break;
    }

    cout << count << endl;

    return 0;
}
