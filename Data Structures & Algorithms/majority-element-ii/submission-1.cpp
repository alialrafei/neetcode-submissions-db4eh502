class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
       int n =  nums.size();
       int army1 = -1, army2 = -1;
       int cnt1 = 0, cnt2 = 0;
       for(int army:nums){
        if(army == army1){
            cnt1++;
        }else if(army==army2){
            cnt2++;
        }else if(cnt1 == 0){
            cnt1 = 1;
            army1 = army;
        }else if(cnt2 == 0){
            cnt2 = 1;
            army2 = army;
        }else{
            cnt1--;
            cnt2--;
        }
       }
       cnt1 = cnt2 = 0;
       for(int army:nums){
        if(army == army1)cnt1++;
        else if(army == army2) cnt2++;
       }
       vector<int> answer;
       if(cnt1 > n/3)answer.push_back(army1);
       if(cnt2 > n/3)answer.push_back(army2);
       return answer;
    }
};