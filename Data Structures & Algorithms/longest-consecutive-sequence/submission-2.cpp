class Solution {
public:
    
    int longestConsecutive(vector<int>& nums) {
       int n = nums.size();
       unordered_set<int> s(nums.begin(),nums.end());
       int answer = 0;
       for(int num:s){
            if(!s.count(num-1)){
                int len = 1;
                int current = num;
                while(s.count(current+1)){
                    current++;
                    len++;
                }
                answer = max(len,answer);
            }
       }
       return answer;
    }
};
