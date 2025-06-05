#include <iostream>
#include <vector>

using namespace std;

int main() {

    string a, b;

    cin >> a >> b;

    vector<int> f(26, 0);

    // a = 0, b = 1,  ..., z = 25
    for (char l : a) {
        f[l - 'a']++;
    }

    for (char l : b) {
        if (l == '*') continue;
        f[l - 'a']--;
        if (f[l - 'a'] < 0) {
            cout << "N" << endl;
            return 0;
        }
    }

    cout << "S" << endl;

    return 0;
}
