#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

//// ESTOURO DE MEMÓRIA
//void gen_seqs(const string &str, vector<string> &seqs) {
//    if (str.size() == 1) {
//        seqs.push_back(str);
//        return;
//    }
//
//    gen_seqs(str.substr(1), seqs);
//
//    int old_size = (int) seqs.size();
//    for (int i = 0; i < old_size; i++) {
//        seqs.push_back(str[0] + seqs[i]);
//    }
//    seqs.push_back(str[0] + string(""));
//}

void gen_seqs(const string &str, set<string> &seqs) {
    if (str.size() == 1) {
        seqs.insert(str);
        return;
    }

    gen_seqs(str.substr(1), seqs);

    set<string> new_seqs;
    for (auto & s : seqs) {
        new_seqs.insert(str[0] + s);
    }
    for (auto & s: new_seqs) {
        seqs.insert(s);
    }
    seqs.insert(str[0] + string(""));
}

int main() {

    string str;

    while (cin >> str) {
        set<string> seqs;

        gen_seqs(str, seqs);

        for (auto &s: seqs) {
            cout << s << endl;
        }

        cout << endl;
    }

    return 0;
}
