//
// Created by IFPE on 09/04/2024.
//

#include <stdio.h>
#include <strings.h>

typedef unsigned long long ulong;

void rotate (char * str, ulong len) {
    char first = str[0];
    for (ulong i = 0; i < len - 1; i++) {
        str[i] = str[i+1];
    }
    str[len - 1] = first;
}

int main() {
    int n = 1;
    char str[100000];
    char min[100000];
    char max[100000];

    scanf("%s", str);

    while (str[0] != '*') {
        strcpy(min, str);
        strcpy(max, str);

        ulong len = strlen(str);
        for (ulong i = 0; i < len; i++) {
            rotate(str, len);
            if (strcmp(str, min) < 0) strcpy(min, str);
            if (strcmp(str, max) > 0) strcpy(max, str);
        }

        printf("Caso %d: %s %s\n", n++, min, max);

        scanf("%s", str);
    }

    return 0;
}
