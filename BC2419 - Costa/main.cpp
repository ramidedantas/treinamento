#include <iostream>

using namespace std;

#define TERRA(i, j) (mapa[i][j] == '#')
#define AGUA(i, j) ((i < 0) || (i >= m) || (j < 0) || (j >= n) || mapa[i][j] == '.')

int main() {

	int m, n;

	cin >> m >> n;

	char mapa[m][n];

	for (int i = 0; i < m; i++) {

		for (int j = 0; j < n; j++) {
			cin >> mapa[i][j];
		}

	}

	int costa = 0;

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (TERRA(i, j) &&
				(AGUA(i, j - 1) ||
				 AGUA(i, j + 1) ||
				 AGUA(i - 1, j) ||
				 AGUA(i + 1, j))) {
				costa++;
//				mapa[i][j] = 'C';
			}
		}
	}

//	for (int i = 0; i < m; i++) {
//		for (int j = 0; j < n; j++) {
//			cout << mapa[i][j];
//		}
//		cout << endl;
//	}

	cout << costa << endl;

	return 0;
}
