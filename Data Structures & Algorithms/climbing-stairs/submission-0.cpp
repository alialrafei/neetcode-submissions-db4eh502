class Solution {
public:
    int solve(int n,vector<int>& mem){
        if(n < 0)
            return 0;
        if(n == 0)
            return 1;
        int &ret = mem[n];
        if(~ret)
            return ret;
        return ret = solve(n-1,mem) + solve(n-2,mem);
    }
    int climbStairs(int n) {
        vector<int> mem(n+1,-1);
        return solve(n,mem);
    }
};