// RAMIDE'S TRAINING
// 2025/02 - Carnaval Tournament
// Problem B
// Finished by 27 Feb 2025
// TIME SPENT: 22min 0s

// Ramide: modificações sobre codigo original de Marcos.

#include <stdio.h>

int main() {
    int n;
    int LEDs[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

    scanf("%d", &n);
    while(getchar()!='\n');

    while (n--) {
        int leds = 0;
        char num[101];
        //fgets(num, 100, stdin);
        //num[strlen(num)-1] = '\0';

        scanf("%s", num);

        for (int i=0; num[i]!='\0'; i++) {
            char letra = num[i];
            leds += LEDs[letra - '0'];
        }

        printf("%d leds\n", leds);
    }

    return 0;
}
