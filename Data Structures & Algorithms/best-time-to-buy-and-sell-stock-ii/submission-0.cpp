class Solution {
   public:
    int solve(int index, int buy, vector<int>& prices, vector<vector<int>>& mem) {
        if (index >= prices.size()) return 0;

        int& ret = mem[index][buy];
        if (ret != -1) return ret;

        if (buy == 0) {
            // skip OR buy
            return ret = max(solve(index + 1, 0, prices, mem),
                             solve(index + 1, 1, prices, mem) - prices[index]);
        } else {
            // skip OR sell
            return ret = max(solve(index + 1, 1, prices, mem),
                             solve(index + 1, 0, prices, mem) + prices[index]);
        }
    }

    int maxProfit(vector<int>& prices) {
        vector<vector<int>> mem(prices.size(), vector<int>(2, -1));
        return solve(0, 0, prices, mem);
    }
};