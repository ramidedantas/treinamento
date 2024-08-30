#include <iostream>

using namespace std;

#define MAX 1000000007L
#define MAX_T 50
#define MAX_LEVELS 100000
typedef unsigned long long ull;

ull t, m, n;

// 50 * 100000 * 8 = 40MB (lim = 1GB)
ull memo[MAX_T][MAX_LEVELS + 1];

ull F(ull level, ull time) {
    if (level < m || level > n) return 0;
    if (time == 1) return 1;

    if (!memo[time - 1][level - m])
        memo[time - 1][level - m] = (F(level + 1, time - 1) + F(level - 1, time - 1)) % MAX;

    return memo[time - 1][level - m];

}

ull progs() {
    ull count = 0;

    for (int i = 0; i < t; i++) {
        for (int j = 0; j <= (n - m); j++) {
            memo[i][j] = 0;
        }
    }

    for (ull i = m; i <= n; i++) {
        count = (count + F(i, t)) % MAX;
    }

    return count;
}

int main() {

    cin >> t >> m >> n;

    ull levels = n - m + 1;

//    ull progs = levels;
//
//    while (--t) {
//        cout << progs << endl;
//        if (progs * 2 < progs) exit(1);
//        if (progs > MAX) exit(2);
////        progs = (((progs % MAX) * 2) % MAX) - 2;
////        progs = (progs % MAX * 2) - 2;
//        progs = progs * 2 - 2;
//    }

//    cout << progs % MAX << endl;
    cout << progs() << endl;

    return 0;
}
