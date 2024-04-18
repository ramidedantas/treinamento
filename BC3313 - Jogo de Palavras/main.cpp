#include <iostream>

#include <string>

using namespace std;

void rotate (string &str) {
    str += str.c_str()[0];
    str = str.substr(1);
}

int mainCPP() {
    int n = 1;
    string str;

    cin >> str;

    while (str != "*") {
        string min = str;
        string max = str;

        for (int i = 0; i < str.length(); i++) {
            rotate(str);
            if (str < min) min = str;
            if (str > max) max = str;
        }

        cout << "Caso " << n++ << ": " << min << " " << max << endl;

        cin >> str;
    }

    return 0;
}
