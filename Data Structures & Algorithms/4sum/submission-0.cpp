class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        const int n = nums.size();
        vector<vector<int>>  answer ;
        sort(nums.begin(),nums.end());
        for(int i = 0 ; i < n ; i++){
            if(i > 0 && nums[i]==nums[i-1])
                continue;
            for(int j = i+1 ; j< n ; j++){
                if(j > i+1 && nums[j] == nums[j-1])
                    continue;
                int front = j+1;
                int back = n-1;
                while(front < back){
                    long long sum = static_cast<long long>(nums[i]) + nums[j] + nums[front]+ nums[back];
                    if(sum == target){
                        answer.push_back({nums[i],nums[j],nums[front],nums[back]});
                        front++;
                        back--;
                        //skip all duplicatation for front;
                        while(front < back && nums[front] == nums[front-1])
                            front++;
                        //skip all duplication for back
                        while(front < back && nums[back] == nums[back+1])
                            back--;
                    }else if(sum > target){
                        back --;
                    }else{
                        front++;
                    }

                }
            }
        }
        return answer;
    }
};

