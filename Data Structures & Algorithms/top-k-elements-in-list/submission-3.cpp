class Solution {
public:
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> count;
        for(int num:nums){
            count[num]++;
        }
        int n = nums.size()+1;
        vector<vector<int>> freqCount(n);
        for(pair<int,int> c: count){
            freqCount[c.second].push_back(c.first);
        }
        vector<int> answer;
        for(int i =n-1 ; i >0 ;i--){
            for(int freq:freqCount[i]){
                answer.push_back(freq);
                if(answer.size() == k){
                    return answer;
                }
            }
        }
        return answer;
    }
};
