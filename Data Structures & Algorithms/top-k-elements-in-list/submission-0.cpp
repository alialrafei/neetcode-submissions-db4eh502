class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        int n = nums.size();
        for(int i = 0 ; i< n ; i ++ ){
            freq[nums[i]]++;
        }
        vector<pair<int,int>> sortedFreq;
        for(int i =0 ; i<n ; i++){
            if(freq[nums[i]]>0)
                sortedFreq.push_back({-1*freq[nums[i]],nums[i]});
            freq[nums[i]]=0;
        }
        sort(sortedFreq.begin(),sortedFreq.end());
        vector<int>answer;
        for(int i =0 ; i<k;i++){
            answer.push_back(sortedFreq[i].second);
        }
        


        return answer;
    }
};