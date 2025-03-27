#include <iostream>

#include <vector>

using namespace std;

class Solution {
public:
    void generate(string last, int n, vector<string> &res) {
        if (n == 0) {
            res.push_back(last);
            return;
        }
        if (last.empty() || last[last.size() - 1] != '0')
            generate(last + '0', n - 1, res);
        generate(last + '1', n - 1, res);
    }

    vector<string> validStrings(int n) {
        vector<string> res;
        generate(string(), n, res);
        return res;
    }
};

int main() {
    int n;
    cin >> n;
    vector<string> sol = Solution().validStrings(n);
    for (auto &s : sol)  cout << s << endl;
    return 0;
}
