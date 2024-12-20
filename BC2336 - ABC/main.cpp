#include <iostream>
#include <algorithm>

#define MOD 1000000007L //10^9 + 7

using namespace std;

typedef unsigned long long ull;

ull to_num(string &str) {
    ull num = 0, base = 1;

    reverse(str.begin(), str.end());

    for (auto c : str) {
        num = (num + (base * (c - 'A'))) % MOD;
        base = (base * 26) % MOD;
    }

    return num;
}

int main() {

    string str;

    while (cin >> str) {
        ull num = to_num(str);

        cout << num << endl;
    }

    return 0;
}
