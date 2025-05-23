#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit_BF(vector<int>& prices) {
        int max_profit = 0;

        for (int i = 0; i < prices.size() - 1; i++) {
            for (int j = i + 1; j < prices.size(); j++) {
                int profit = prices[j] - prices[i];
                max_profit = max(max_profit, profit);
            }
        }

        return max_profit;
    }

    int maxProfit(vector<int>& prices) {
        int max_profit = 0;
        int min_price = prices[0];
        for (int p : prices) {
            min_price = min(p, min_price);
            max_profit = max(max_profit, p - min_price);
        }
        return max_profit;
    }
};

int main() {
//    vector<int> prices = {7, 1, 5, 3, 6, 4};
    vector<int> prices = {7, 6, 4, 3, 1};

    cout << Solution().maxProfit(prices) << endl;

    return 0;
}
