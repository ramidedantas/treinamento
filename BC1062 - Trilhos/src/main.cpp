#include <iostream>
using namespace std;

int main() {

	int n;

	cin >> n;

	while (n) { // n == 0 -> fim da entrada

		while (true) {
			int a = 1, b[1000];
			int yes = 0;

			cin >> b[0];

			if (!b[0]) break; // fim de bloco

			for (int i = 1; i < n; i++) {
				cin >> b[i];
			}

			int pilha[1000], topo = -1;

			int i = 0;
			while ((a <= n + 1) && (i < n)) {
				if (topo >= 0 && pilha[topo] == b[i]) {
					topo--;
					i++;
				} else {
					pilha[++topo] = a++;
				}
			}

            // a == n + 1: varreu todos do lado A
            // i == n: varreu todos do lado B
			yes = (a == n + 1) && (i == n);

			cout << (yes?"Yes":"No") << endl;
		}

		cout << endl;

		cin >> n;
	}

	return 0;
}
