#include <iostream>
#include <vector>
#include <numeric>
#include <map>

using namespace std;

int lcm(const vector<int> &nums) {
    int res = 1;
    for (auto n : nums) {
        res = lcm(res, n);
    }
    return res;
}

map<int, int> factors(int n) {
    map<int, int> f;
    for (int x = 2; x*x <= n; x++) {
        while (n%x == 0) {
            f[x]++;
            n /= x;
        }
    }
    if (n > 1) f[n]++;
    return f;
}

int number(map<int, int> &fac) {
    int res = 1;
    for (auto [f, p] : fac) {
        while (p--) {
            res *= f;
        }
    }
    return res;
}

int main() {
    int n, l;

    cin >> n >> l;

    vector<int> nums(n);

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int mmc = lcm(nums); // 42
    int dl = (l / mmc);  // 512 / 42 = 12,19...
    int ql = dl * mmc;   // 12 * 42 = 504

    // 504 = 2^3 x 3^2 x 7
    // 42  = 2   x 3   x 7
    //  x  = 2^3 x 3^2 x 7

    map<int, int> qf = factors(ql); // 504 = 2^3 x 3^2 x 7
    map<int, int> df = factors(dl); // 12 = 2^2 x 3

    map<int, int> af;  // 2^3 x 3^2 = 72

    for (auto [f, c] : df) {
        af[f] = qf[f];
    }

    int ans = number(af);

    cout << ans << endl;

    return 0;
}
