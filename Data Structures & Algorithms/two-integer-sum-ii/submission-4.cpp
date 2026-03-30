class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0;
        int r = numbers.size()-1;
        vector<int> answer;
        while(l<r){
            int curSum = numbers[r]+numbers[l];
            if(curSum > target)
                r--;
            else if(curSum < target)
                l++;
            else
                return {l+1,r+1};
        }
        return answer;
    }
};
