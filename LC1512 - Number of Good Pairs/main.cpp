#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        vector<int> counts(101,0);
        int pairs = 0;

        for (int v : nums) {
            counts[v]++;
        }

        for (int v : counts) {
            if (v < 2) continue; // desnecessário? n = 0 -> 0; n = 1 -> 0
            pairs += v * (v - 1) / 2;
        }

        return pairs;
    }
};

int main() {
    int n;

    cin >> n;

    vector<int> input(n);

    for (int i = 0; i < n; i++) {
        cin >> input[i];
    }

    cout << Solution().numIdenticalPairs(input) << endl;

    return 0;
}
