#include <iostream>
#include <vector>

using namespace std;

int main() {

    vector<int> cartas(0);
    string carta;

    while (cin >> carta) {
        if (carta == "A") cartas.push_back(1);
        else if (carta == "J") cartas.push_back(11);
        else if (carta == "Q") cartas.push_back(12);
        else if (carta == "K") cartas.push_back(13);
        else cartas.push_back(stoi(carta));
    }

    vector<string> labels(14);
    labels[1] = "A";
    labels[11] = "J";
    labels[12] = "Q";
    labels[13] = "K";

    for (int i = 1; i < cartas.size(); i++) {
        int c = cartas[i];
        int j = i;
        for (; j > 0 && c < cartas[j - 1]; j--) {
            cartas[j] = cartas[j - 1];
        }
        cartas[j] = c;

        for (auto & x : cartas) {
            string str = (x == 1 || x > 10)?labels[x]:to_string(x);
            cout << str << " ";
        }
        cout << endl;
    }

    return 0;
}
