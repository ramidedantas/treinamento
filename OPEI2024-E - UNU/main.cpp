#include <iostream>
#include <list>
#include <vector>

using namespace std;

struct carta {
    int num;
    string cor;
    bool jogada = false;
};

int main() {

    vector<carta> cartas(0);
    carta na_mesa, prox;
    int mesma_cor = 0;
    int mesmo_num = 0;

    cin >> na_mesa.num >> na_mesa.cor;

    while (cin >> prox.num, prox.num) {
        cin >> prox.cor;
        cartas.push_back(prox);
        if (prox.num == na_mesa.num) mesmo_num++;
        if (prox.cor == na_mesa.cor) mesma_cor++;
    }

    if (cartas.empty()) {
        cout << "Voce ja bateu!" << endl;
        return 0;
    }

    int num_jogadas = 0;

    if (mesmo_num > mesma_cor) {
        cout << "Eh melhor jogar uma sequencia de numeros" << endl;
        for (int i = 0; i < cartas.size(); i++) {
            carta &c = cartas[i];
            if (c.num == na_mesa.num) {
                cout << "- Jogou a carta " << c.num << " da cor " << c.cor << endl;
                c.jogada = true;
                num_jogadas ++;
                if (cartas.size() - num_jogadas == 1) {
                    cout << "- UNU!" << endl;
                }
            }

        }
    } else {
        cout << "Eh melhor jogar uma sequencia de cores" << endl;
        for (int i = 0; i < cartas.size(); i++) {
            carta &c = cartas[i];

            if (c.cor == na_mesa.cor) {
                cout << "- Jogou a carta " << c.num << " da cor " << c.cor << endl;
                c.jogada = true;
                num_jogadas ++;
                if (cartas.size() - num_jogadas == 1) {
                    cout << "- UNU!" << endl;
                }
            }
        }
    }

    if (cartas.size() == num_jogadas) {
        cout << "- Bati!" << endl;
    } else {
        cout << "Ainda ficou com as seguintes cartas:" << endl;
        for (auto &c : cartas) {
            if (!c.jogada)
                cout << "- " << c.num << " " << c.cor << endl;
        }
    }

    return 0;
}
