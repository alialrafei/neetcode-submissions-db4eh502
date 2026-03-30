class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int countNonVal = 0;
        vector<int> newNums;
        for(int num:nums){
            if(num!=val){
                countNonVal++;
                newNums.push_back(num);
            }
        }
        nums = newNums;
        return countNonVal;
    }
};