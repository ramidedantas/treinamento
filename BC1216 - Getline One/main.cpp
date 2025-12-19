#include <iomanip>
#include <iostream>

using namespace std;

int main() {
    string nome;
    int distancia, n = 0;
    double soma = 0;

    getline(cin, nome);
    while (cin >> distancia) { // CLion tem problemas com EOF testando no console
        cin.ignore(); // necessário para ignorar quebra de linha >:(
        soma += distancia;
        n++;
        getline(cin, nome);
    }

    cout << fixed << setprecision(1) << (soma / n) << endl;

    return 0;
}
