#include <iostream>
#include <queue>

using namespace std;

int main() {
    int n;
    cin >> n;

    // D[0] = left -> right
    // D[1] = right -> left
    queue<int> D[2];

    while (n--) {
        int t, d;
        cin >> t >> d;
        D[d].push(t);
    }

    int time = 0, next_stop, dir = -1;

    while (!D[0].empty() || !D[1].empty()) {
//        if (dir == -1) {
//            dir = D[0].empty()?1:(D[1].empty()?0:D[0].front() > D[1].front());
//            time = max(time, D[dir].front()); D[dir].pop();
//            next_stop = time + 10;
//        } else if (dir == 0 && !D[0].empty() && D[0].front() < next_stop) {
//            time = max(time, D[0].front());
//            D[0].pop();
//            next_stop = time + 10;
//        } else if (dir == 1 && !D[1].empty() && D[1].front() < next_stop) {
//            time = max(time, D[1].front());
//            D[1].pop();
//            next_stop = time + 10;
//        } else {
//            time = next_stop;
//            dir = -1;
//        }

        bool has_next;
        if (dir == -1) { // parado, proximo é o menor na frente das filas 0 e 1
            dir = D[0].empty()?1:(D[1].empty()?0:D[0].front() > D[1].front());
            has_next = true;
        } else { // em movimento, proximo é aquele que chega antes da proxima parada
            has_next = !D[dir].empty() && D[dir].front() < next_stop;
        }

        if (has_next) { // pega próximo, retida da fila, seta tempo atual e próxima parada
            time = max(time, D[dir].front());
            D[dir].pop();
            next_stop = time + 10;
        } else { // escada parou antes de chegar próximo
            time = next_stop;
            dir = -1;
        }
    }

    cout << next_stop << endl;

    return 0;
}
