class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int majorElement = nums[0];
        int count = 1;
        int n = nums.size();
        for(int i = 1 ; i < n ; i ++){
            if(nums[i]==majorElement){
                count++;
            }else{
                count--;
            }
            if(!count){
                count = 1;
                majorElement = nums[i];
            }
        }
        return majorElement;
    }
};