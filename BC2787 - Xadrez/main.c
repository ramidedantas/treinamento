#include <stdio.h>

int main() {
    int l, c;
    scanf("%d %d", &l, &c);
    printf("%d\n", 1 - ((l + c) % 2));
    return 0;
}
