#include <iostream>

using namespace std;

int matrix[200][200];

// DFS
// Área a partir da celula (i,j) com a cor dada
int area(int h, int l, int i, int j, int cor) {
    if (matrix[i][j] != cor) return 0;
    if ((i < 0) || (i >= h) || (j < 0) || (j >= l)) return 0;

    matrix[i][j] = -1;

    return 1 +
        area(h, l, i + 1, j, cor) +
        area(h, l, i, j + 1, cor) +
        area(h, l, i - 1, j, cor) +
        area(h, l, i, j - 1, cor);
}


int area(int h, int l, int i, int j) {
    if (matrix[i][j] == -1) return 99999;

    return area (h, l, i, j, matrix[i][j]);
}

int main() {
    int h, l;

    cin >> h >> l;

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < l; j++) {
            cin >> matrix[i][j];
        }
    }

    int min_area = 99999;

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < l; j++) {
            min_area = min(min_area, area(h, l, i, j));
        }
    }

    cout << min_area << endl;

    return 0;
}
