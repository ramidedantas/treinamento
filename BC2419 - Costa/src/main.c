#include <stdio.h>

#define TERRA(i, j) (mapa[i][j] == '#')
#define AGUA(i, j) ((i < 0) || (i >= m) || (j < 0) || (j >= n) || mapa[i][j] == '.')

int main() {

	int m, n, costa = 0;

	scanf("%d %d", &m, &n);

	// array de strings, não caracteres
	char mapa[m][n + 1]; // OK em C99

	for (int i = 0; i < m; i++) {
		scanf("%s", mapa[i]);
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if ( TERRA(i, j) &&
				(AGUA(i, j - 1) ||
				 AGUA(i, j + 1) ||
				 AGUA(i - 1, j) ||
				 AGUA(i + 1, j))) {
				costa++;
				mapa[i][j] = 'C';
			}
		}
	}

//	for (int i = 0; i < m; i++) {
////		for (int j = 0; j < n; j++) {
//			printf("%s\n", mapa[i]);
////		}
//	}

	printf("%d\n", costa);

	return 0;
}
