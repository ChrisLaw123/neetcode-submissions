class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //we want to minimize the buy, maximize the sell (find the biggest positive difference)
        set<int> buy;
        int max{};
        for (int i{}; i < prices.size(); i++) {
            buy.insert(prices[i]);
            if (prices[i] - *buy.begin() > max) {
                max = prices[i] - *buy.begin();
            }
        }

        return max;

    }
};
