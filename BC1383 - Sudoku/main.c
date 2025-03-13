// RAMIDE'S TRAINING
// 2025/02 - Carnaval Tournament
// Problem D
// Finished by 27 Feb 2025
// TIME SPENT: 45min

// Ramide: modificações sobre codigo original de Marcos.

#include <stdio.h>

// Ramide
int checar(int check[9]) {
    int found[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};

    for (int i = 0; i < 9; i++) {
        if (found[check[i] - 1]) return 0;
        found[check[i] - 1] = 1;
    }

    return 1;
}

int main() {

    int n;
    scanf("%d", &n);

    int check[9];

    /*
    for (int i=0; i<9; i++) {
      check[i][0] = i+1;
      check[i][1] = 0;
    }
    */


    for (int h=0; h<n; h++) {

        int matrix[9][9];

        int passou = 1;

        for (int i=0; i<9; i++) {
            for (int j=0; j<9; j++) {
                scanf("%d", &matrix[i][j]);
                check[j] = matrix[i][j];
            }

            if (passou) {
                passou = checar(check);
            }

        }

        if (passou) {

            for (int i=0; i<9; i++) {
                for (int j=0; j<9; j++) {
                    check[j] = matrix[j][i];
                }

                passou = checar(check);
                if (!passou) {
                    break;
                }
            }
        }

        if (passou) {

            int iMultipl = 0;
            int jMultipl = 0;

            for (int iMultipl=0; iMultipl<3; iMultipl++) {
                for (int jMultipl=0; jMultipl<3; jMultipl++) {

                    int idx = 0;
                    for (int i=3*iMultipl; i<(3*iMultipl)+3; i++) {
                        for (int j=3*jMultipl; j<(3*jMultipl)+3; j++) {
                            check[idx++] = matrix[j][i];
                        }
                    }

                    passou = checar(check);
                    if (!passou) {
                        break;
                    }

                }
                if (!passou) {
                    break;
                }
            }


        }

        printf("Instancia %d\n", h+1);
        if (passou) {
            printf("SIM\n");
        } else {
            printf("NAO\n");
        }
        printf("\n");



        /*
        for (int i=0; i<9; i++) {
          for (int j=0; j<9; j++) {
            printf("%d.", matrix[i][j]);
          }
          printf("\n");
        }
        */

    }

    return 0;
}
