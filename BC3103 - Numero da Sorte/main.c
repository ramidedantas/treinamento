#include <stdio.h>
#include <string.h>

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        char str[102];
        scanf("%s", str);

        int digs[10];
        memset(digs, 0, sizeof(digs));

        int len = strlen(str);
        int menor = 9;

        for (int i=0; i<len; i++) {
            int n = str[i] - '0';
            digs[n]++;
            if (n < menor && n > 0) menor = n;
        }

        printf("%c", menor + '0'); // (+ '0') = (+ 48)
        digs[menor]--;

        for (int d = 0; d <= 9; d++) {
            while (digs[d]--) printf("%c", d + '0');
        }

        printf("\n");

    }

    return 0;
}