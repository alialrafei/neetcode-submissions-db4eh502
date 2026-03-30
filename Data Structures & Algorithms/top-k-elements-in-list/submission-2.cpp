class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        vector<vector<int>> freq(nums.size() + 1);

        for (int num : nums) {
            count[num] ++;
        }
        //bucket sort the count not the value so freq[5] -> 1,100,2 and so on 
        for(const auto& entry : count){
            freq[entry.second].push_back(entry.first);
        }
        vector<int>res;
        for(int i = freq.size()-1;i>0;i--){
            for(int num : freq[i]){
                res.push_back(num);
                if(res.size()==k){
                    return res;
                }
            }
        }
        return res;
    }
};