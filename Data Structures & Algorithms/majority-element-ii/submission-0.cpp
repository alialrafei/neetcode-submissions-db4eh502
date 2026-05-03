class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int>count;
        unordered_set<int> s(nums.begin(),nums.end());
        vector<int> answer;
        for(int num:nums){
            count[num]++;
        }
        int n = nums.size();
        int check = n/3;
        for(int num:s){
            int sz = count[num];
            if(sz>check){
                answer.push_back(num);
            }
            if(answer.size()==3)
                break;
        }
        return answer;
    }
};