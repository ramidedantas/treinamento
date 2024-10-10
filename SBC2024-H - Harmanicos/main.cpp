#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

typedef unsigned long long ull;

void variations(string &str, list<string> &res) {
    int pos = (int)str.find('*');

    if (pos == string::npos) {
        res.emplace_back(str);
    } else {
        string str0 = string(str);
        string str1 = string(str);
        str0[pos] = '0';
        str1[pos] = '1';
        variations(str0, res);
        variations(str1, res);
    }
}

list<string> variations(string &bin_str) {
    list<string> res;

    variations(bin_str, res);

    return res;
}

ull number(const string &bin_str) {
    ull res = 0;

    string bin_str_rev = string(bin_str);
    reverse(bin_str_rev.begin(), bin_str_rev.end());

    ull val = 1ULL;

    for (char b : bin_str_rev) {
        if (b == '1') res += val;
        val *= 2;
    }

    return res;
}

bool divisor(const string &m, const string &n) {
    ull k = number(n);

    ull pow = 1;
    ull res = 0;

    for (int i = 0; i < m.size(); i++) {
        char bit = m[m.size() - i - 1];
        if (bit == '1') res = ((pow % k) + (res % k)) % k;
        pow = ((2 % k) * (pow % k)) % k;
    }

    return res == 0;
}

int main() {

    string m, n;

    cin >> m >> n;

    list<string> m_list = variations(m);
    list<string> n_list = variations(n);

//    for (const string & s : m_list) {
//        cout << s << endl;
//    }

    for (const string &m_str : m_list) {
        for (const string &n_str : n_list) {
            if (divisor(m_str, n_str)) {
                cout << m_str << endl;
                return 0;
            }
        }
    }

    cout << "ERRO" << endl;

    return -1;
}
