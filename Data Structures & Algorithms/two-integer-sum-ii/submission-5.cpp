class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        int ed = n-1;
        int st = 0;
        while(st<ed){
            int curSum = numbers[st]+numbers[ed];
            
            if(curSum>target)
                ed--;
            else if(curSum<target)
                st++;
            else
                return {st+1,ed+1};
        }
        return {};
    }
};
