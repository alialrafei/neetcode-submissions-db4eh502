#include <bits/stdc++.h>
class Solution {
public:
int mem[100][2];

    int solve(vector<int> &prices, int i, int holding) {
        if (i == prices.size())
            return 0;

        int &ret = mem[i][holding];
        if (ret != -1)
            return ret;

        if (holding == 0) {
            // buy or skip
            ret = max(
                -prices[i] + solve(prices, i + 1, 1),
                solve(prices, i + 1, 0)
            );
        } else {
            // sell or skip
            ret = max(
                prices[i],
                solve(prices, i + 1, 1)
            );
        }

        return ret;
    }
    int maxProfit(vector<int>& prices) {
        memset(mem,-1,sizeof(mem));
        return solve(prices, 0, 0);
    }
};
