
#include <iostream>

using namespace std;

int main() {

	int n;

	while (cin >> n) {
		int h, m, c, crit = 0;

		int hora = 7 * 60; // hora livre

		while (n--) {
			cin >> h >> m >> c;

			int chegada = h * 60 + m;

			int critico = chegada + c;

			int proxima = ((chegada + 29)/30) * 30;

			int atendimento = max(hora, proxima);

			hora = atendimento + 30;

			if (atendimento > critico)
				crit ++;
		}

		cout << crit << endl;
	}

	return 0;
}
