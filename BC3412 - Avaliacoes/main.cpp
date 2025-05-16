#include <iostream>
#include <vector>
#include <sstream>
#include <iomanip>

using namespace std;

int main() {
    int n;

    cin >> n;
    cin.get();

    while(n--) {
        string name;
        string notas_str;
        string nota;
        vector<double> notas;

        getline(cin, name);
        getline(cin, notas_str);

        stringstream notas_stream(notas_str);
        while (getline(notas_stream, nota, ' '))
            notas.push_back(stod(nota));

        double soma = 0;
        int num = (notas.size() <= 2)?2:3;
        for (double n_: notas)
            soma += n_;

        if (notas.size() == 4) {
            double menor = notas[0];
            for (double nn : notas)
                menor = min(menor, nn);
            soma -= menor;
        }

        double media = soma / num;

        cout << name << ": " << fixed << setprecision(1) << media << endl;
    }


    return 0;
}
