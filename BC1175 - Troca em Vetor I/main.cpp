#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n = 20;

    vector<int> N(n);

    for (int i = 1; i <= n; i++) {
        cin >> N[n - i];
    }

    for (int i = 0; i < n; i++) {
        cout << "N[" << i << "] = " << N[i] << endl;
    }

    return 0;
}