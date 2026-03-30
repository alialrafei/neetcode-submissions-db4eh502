class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int prefix = 0;
        vector<int>answer(n,0);
        
        for(int i =n-1;i>=0;i--){
            if(i==n-1)
                answer[i]=nums[i];
            else
                answer[i] = answer[i+1]*nums[i];
        }
        
        for(int i =0;i<n;i++){
            
            if(i==0){
                answer[i] = answer[i+1];
                prefix = nums[i];
                continue;
            }
            if(i==n-1){
                answer[i] = prefix;
                continue;
            }
            answer[i] = prefix * answer[i+1];
            prefix = prefix * nums[i];
        }
        return answer;
    }
};