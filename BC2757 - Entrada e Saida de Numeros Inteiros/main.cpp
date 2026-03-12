#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int a, b, c;

    cin >> a >> b >> c;

    // right: alinha a direita
    // left: alinha a esquerda
    // setw(10): preenche até ficar com 10 caracteres pelo menos
    // setfill('0'): preenche com zeros
    // internal [ao final]: preenchimento fica entre sinal e número
    cout << "A = " << a <<", B = " << b <<", C = " << c << endl;

    cout << "A = " << right << setfill(' ') << setw(10) << a <<", "; // setfill(' ') opcional
    cout << "B = " << right << setfill(' ') << setw(10) << b <<", ";
    cout << "C = " << right << setfill(' ') << setw(10) << c << endl;
    cout << "A = " << right << setfill('0') << setw(10) << internal << a <<", ";
    cout << "B = " << right << setfill('0') << setw(10) << internal << b <<", ";
    cout << "C = " << right << setfill('0') << setw(10) << internal << c << endl;
    cout << "A = " << left << setfill(' ') << setw(10)  << a <<", ";
    cout << "B = " << left << setfill(' ') << setw(10) << b <<", ";
    cout << "C = " << left << setfill(' ') << setw(10) << c << endl;

    return 0;
}