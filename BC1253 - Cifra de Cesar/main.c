#include <stdio.h>
git
int main() {
    int n;
    scanf("%d", &n);

    while(n--) {
        char str[51];
        int shift;

        scanf("%s", str);
        scanf("%d", &shift);

        for (int i=0; str[i]!='\0'; i++) {
            int letra = str[i] - 'A';

            letra = ((letra - shift) + 26) % 26;

            str[i] = (char)letra + 'A';
        }

        printf("%s\n", str);
    }

    return 0;
}

