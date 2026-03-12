#include <stdio.h>

int main() {
  int n;
  scanf("%d", &n);

  int soma_bruta = 0;
  int soma_resto = 0;

  while (n--) {
    int qnt;
    scanf("%d", &qnt);

    soma_bruta += qnt;
    soma_resto += qnt % 3;
  }

  printf("%d\n", soma_bruta - soma_resto);

  return 0;
}
