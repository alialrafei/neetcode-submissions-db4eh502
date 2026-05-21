class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int current_index = 1;
        int n = nums.size();
        for (int i = 1; i < n; i++) {
           if(nums[i-1] != nums[i]){
            nums[current_index] = nums[i];
            current_index++;
           }
        }
        return current_index;
    }
};