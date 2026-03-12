#include <stdio.h>

int main() {
    unsigned long long a, b, n, sum = 0;

    scanf("%llu%llu", &a, &b); // C

    //for (long long i = x; x <= y; x++) {
    //    sum += i;
    //}

    n = (b - a + 1);
    sum =  n * (a + b) / 2;

    printf("%llu\n", sum);

    return 0;
}
