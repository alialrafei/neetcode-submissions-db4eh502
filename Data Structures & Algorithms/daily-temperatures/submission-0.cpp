class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
       int n = temperatures.size();
       stack<pair<int,int>>temp_days;
       vector<int>answer(n);
       for(int i = n-1 ; i >= 0; i-- ){
           while(!temp_days.empty() && temp_days.top().first <=  temperatures[i]){
               temp_days.pop();
           }
           if(temp_days.empty())
              answer[i] = 0;
           else 
              answer[i] = temp_days.top().second-i;
            temp_days.push({temperatures[i],i});
       }
       return answer;
        
    }
};