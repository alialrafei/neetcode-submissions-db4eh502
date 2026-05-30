class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        int end = 0;
        unordered_set<int> nums_index;
        for(int i = 0; i < n ; i++){
            if(nums_index.count(nums[i])){
              return true;
               
            }
            nums_index.insert(nums[i]);
            if (nums_index.size() > k) {
                nums_index.erase(nums[i - k]);
            }
             
        }
        return false;
    }
};
