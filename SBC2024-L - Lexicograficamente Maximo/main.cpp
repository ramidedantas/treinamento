#include <iostream>
#include <vector>

#define NUM_BITS 64

typedef unsigned long long ull;

using namespace std;

vector<ull> binary(ull a) {
    vector<ull> bin(NUM_BITS, 0);

    for (int i = 0; i < NUM_BITS; i++) {
        bin[i] = (ull)(a & 1ULL);
        a >>= 1;
    }

    return bin;
}

ull number(vector<ull> bin) {
    ull res = 0;

    int mul = 1;
    for (int i = 0; i < NUM_BITS; i++) {
        if (bin[i]) res += mul;
        mul <<= 1;
    }

    return res;
}

int main() {
    int n;

    cin >> n;

    vector<ull> counters(NUM_BITS, 0);

    for (int i = 0; i < n; i++) {
        ull a;
        cin >> a;

        vector<ull> a_bin = binary(a);

        for (int j = 0; j < NUM_BITS; j++) {
            counters[j] += a_bin[j];
        }
    }

    for (int i = 0; i < n; i++) {
        ull a = number(counters);
        cout << a << " ";
        for (int j = 0; j < NUM_BITS; j++) {
            if (counters[j]) counters[j]--;
        }
    }
    cout << endl;

    return 0;
}
