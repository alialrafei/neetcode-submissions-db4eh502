class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> answer;
        for(int i = 0 ; i < 2 ; i ++ ){
            for(int x:nums){
                answer.push_back(x);
            }
        }
        return answer;
    }
};