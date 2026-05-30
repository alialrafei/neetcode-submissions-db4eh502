class Solution {
public:
    const static int kMax = (int)1e5+9;
    int solve(vector<int>& cost, vector<int>& dp, int& n , int current_step){
        if(current_step > n )
            return kMax;
        if(current_step == n)
            return 0;

        int &ret = dp[current_step];
        if(~ret)
            return ret;
        return ret = min(solve(cost,dp,n,current_step+2)+cost[current_step],solve(cost,dp,n,current_step+1)+cost[current_step]);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int>dp(n,-1);
        return min(solve(cost,dp,n,0),solve(cost,dp,n,1));
    }
};