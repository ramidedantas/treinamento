#include <iostream>
#include <vector>

using namespace std;

string match(const string &senha, const string &tentativa) {
    string m;
    vector<bool> b(senha.size(), false);
    vector<bool> w(senha.size(), false);

    for (int i = 0; i < tentativa.size(); i++) {
        if (tentativa[i] == senha[i]) {
            m += 'b';
            b[i] = true;
        }
    }

    for (int i = 0; i < tentativa.size(); i++) {
        if (b[i]) continue;
        auto p = senha.find(tentativa[i]);
        if (p != string::npos && !b[p] && !w[p]) {
            m += 'w';
            w[p] = true;
        }
    }

    while (m.size() < senha.size()) m += '-';

    return m;
}

int main() {
    string senha;
    string tentativa;

    cin >> senha;

    int t = 0;
    while (cin >> tentativa) {
        t++;
        string m = match(senha, tentativa);
        cout << m << endl;
        if (m == "bbbb") {
            cout << "Senha encontrada em " << t << " tentativas" << endl;
        }
    }

    return 0;
}
