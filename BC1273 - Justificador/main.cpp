
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
	int n;
	cin >> n;

	while (n) {
		string w[n];

		auto longest = w[0].size();

		for (int i = 0; i < n; i++) {
			cin >> w[i];

			longest = max(w[i].length(), longest);
		}

		for (int i = 0; i < n; i++) {
			cout << right << setw((int)longest) << w[i] << endl;
		}

		cin >> n;

		// soh botar linha branco se houver um proximo teste
		// do contrario: presentation error
		if (n) cout << endl;
	}

	return 0;
}
