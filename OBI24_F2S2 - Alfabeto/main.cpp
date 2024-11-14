#include <iostream>

using namespace std;

int main() {
    int k, n;

    cin >> k >> n;

    string alfa;
    string msg;

    cin >> alfa >> msg;

    for (char s : msg) {
        if (alfa.find(s) == string::npos) {
            cout << "N" << endl;
            return 0;
        }
    }

    cout << "S" << endl;

    return 0;
}
