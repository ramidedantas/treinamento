#include <iostream>
#include <vector>

using namespace std;

bool check(const vector<bool>& notes, const vector<bool>& scale) {
    for (int i = 0; i < notes.size(); i++) {
        if (notes[i] && !scale[i]) return false;
    }
    return true;
}

void shift(vector<bool> &scale) {
    bool last = scale.back();
    for (int i = (int)scale.size() - 1; i > 0; i--) {
        scale[i] = scale[i - 1];
    }
    scale[0] = last;
}

int main() {
    int n;
    vector<bool> notas(12, false);
    vector<bool> maior = {true,     // do
                          false,    // do#
                          true,     // re
                          false,    // re#
                          true,     // mi
                          true,     // fa
                          false,    // fa#
                          true,     // sol
                          false,    // sol#
                          true,     // la
                          false,    // la#
                          true};    // si
    vector<string> nomes = {"do",
                            "do#",
                            "re",
                            "re#",
                            "mi",
                            "fa",
                            "fa#",
                            "sol",
                            "sol#",
                            "la",
                            "la#",
                            "si"};

    cin >> n;

    while (n--) {
        int nota;
        cin >> nota;
        notas[(nota - 1) % 12] = true;
    }

    for (int i = 0; i < 12; i++) {  // do(0) -> si (11)
        if (check(notas, maior)) {
            cout << nomes[i] << endl;
            return 0;
        }
        shift(maior);
    }

    cout << "desafinado" << endl;

    return 0;
}
