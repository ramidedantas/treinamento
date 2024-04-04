
#include <iostream>

#include <iomanip>

using namespace std;

int mainCPP() {
	int n;
	cin >> n;

	while (n) {
		string w[n];

		int max = -1;

		for (int i = 0; i < n; i++) {
			cin >> w[i];

			if (w[i].length() > max) max = w[i].length();
		}

		for (int i = 0; i < n; i++) {
			cout << setw(max) << w[i] << endl;
		}

		cin >> n;

		// só botar linha branco se houver um próximo teste
		// do contrário: presentation error
		if (n) cout << endl;
	}

	return 0;
}
