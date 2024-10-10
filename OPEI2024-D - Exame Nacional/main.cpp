#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct candidato {
    string nome;
    string cpf;
    int nota;
    int idade;

    bool operator <(const candidato& c) const {
        if (nota == c.nota)
            return idade > c.idade;
        return nota > c.nota;
    }
};

int main() {

    int n;

    cin >> n;

    vector<candidato> arr(n);

//    for (int i = 0; i < n; i++) {
//        cin >> arr[i].nome >> arr[i].cpf >> arr[i].nota >> arr[i].idade;
//    }

    for (auto &c : arr) {
        cin >> c.nome >> c.cpf >> c.nota >> c.idade;
    }

    sort(arr.begin(), arr.end());

    for (auto &c : arr) {
        cout << c.nome << " | " << c.cpf << endl;
    }

    return 0;
}
