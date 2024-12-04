#include <iostream>

using namespace std;

int main() {

    int n, h, w;

    cin >> n >> h >> w;

    while (n--) {
        char h_w, w_h;
        cin >> h_w >> w_h;

        if (h_w == 'Y' && h > 0 || w == 0) {
            cout << "Y" << " ";
            h--;
            w++;
        }  else {
            cout << "N" << " ";
        }
        if (w_h == 'Y' && w > 0 || h == 0) {
            cout << "Y" << endl;
            w--;
            h++;
        } else {
            cout << "N" << endl;
        }
    }

    return 0;
}
