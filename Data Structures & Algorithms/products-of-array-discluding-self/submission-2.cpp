class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> right(n+1,0);
        right[n] = 1;
        for(int i = n-1;i>=0;i--){
            right[i] = right[i+1] * nums[i];
        }
        int cur = nums[0];
        vector<int> answer;
        for(int i = 0 ; i < n ; i ++){
            int curMut = 0;
            if(i==0){
                curMut = right[i+1];
                  answer.push_back(curMut);
                continue;
            }
            curMut = right[i+1]*cur;
            answer.push_back(curMut);
            cur*=nums[i];
        }
        return answer;
    }
};
