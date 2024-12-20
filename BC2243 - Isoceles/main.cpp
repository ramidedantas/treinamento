#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);

    for (auto &v : arr) {
        cin >> v;
    }

    int l = 0;
    for (auto &v : arr) {
        l = v = min(l + 1, v);
    }

    reverse(arr.begin(), arr.end());

    int r = 0;
    for (auto &v : arr) {
        r = v = min(r + 1, v);
    }

    cout << *max_element(arr.begin(), arr.end()) << endl;

    return 0;
}
