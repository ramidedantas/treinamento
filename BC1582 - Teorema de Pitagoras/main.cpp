#include <iostream>

using namespace std;

int pitagorica(int cat1, int cat2, int hipo) {
    return (cat1*cat1 + cat2*cat2) == (hipo*hipo);
}

int mdc(int a, int b) {
    return (b)? mdc(b, a % b) : a;
}

int primitiva(int a, int b, int c) {
    return mdc(a, mdc(b, c)) == 1;
}

int main() {

    int a, b, c;

    while (cin >> a >> b >> c) {
        int hipo = max(a, max(b, c));
        int cat1 = min(a, min(b, c));
        int cat2 = (a + b + c) - hipo - cat1;

        if (pitagorica(cat1, cat2, hipo)) {
            if (primitiva(cat1, cat2, hipo)) {
                cout << "tripla pitagorica primitiva" << endl;
            } else {
                cout << "tripla pitagorica" << endl;
            }
        } else {
            cout << "tripla" << endl;
        }
    }

    return 0;
}
