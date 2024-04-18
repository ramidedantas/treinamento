#include <iostream>

using namespace std;

int main() {

    string mensagem;
    string crib;

    cin >> mensagem >> crib;

    auto mens_len = mensagem.length();
    auto crib_len = crib.length();
    auto shifts = mens_len - crib_len + 1;

    int matches = 0;

    for (auto i = 0; i < shifts; i++) {
        for (auto j = 0; j < crib_len; j++) {
            if (mensagem[i + j] == crib[j]) {
                matches++;
                break;
            }
        }
    }

    cout << shifts - matches << endl;

    return 0;
}
