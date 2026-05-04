class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int curSum = 0,cnt =0;
        int n = nums.size();
        unordered_map<int,int>mp;
        mp[0] = 1;
        for(int i =0; i < n ; i ++){
            curSum += nums[i];
            if(mp.find(curSum-k)!=mp.end()){
                cnt+= mp[curSum-k];
            }
            mp[curSum]++;
        }
        return cnt;
    }
};