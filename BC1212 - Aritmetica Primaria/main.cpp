#include <algorithm>
#include <iostream>

using namespace std;
int main() {

    string line;
    getline(cin, line);

    while (line != "0 0") {
    // while (num1 != "0" && num2 != "0") {
        // cin >> num1 >> num2;
        auto pos = line.find(' ');
        string num1 = line.substr(0, pos);
        string num2 = line.substr(pos + 1);

        auto lm = max(num1.size(), num2.size());

        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());

        while (num1.length() < lm) num1 += '0';
        while (num2.length() < lm) num2 += '0';

        int carry = 0, count = 0;
        for (int i = 0; i < lm; i++) {
            int v1 = num1[i] - '0';
            int v2 = num2[i] - '0';
            carry = (v1 + v2 + carry) >= 10 ? 1 : 0;
            count += carry;
        }

        if (count == 0) {
            cout << "No carry operation." << endl;
        } else if (count == 1) {
            cout << "1 carry operation." << endl;
        } else {
            cout << count << " carry operations." << endl;
        }

        getline(cin, line);
        // cin >> num1 >> num2;
    }

    return 0;
}