class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {

        int n = gas.size();
        int total_value = 0;
        int current_value = 0;
        int gas_station = 0;
        for (int i = 0; i < n; i++) {
             total_value += gas[i]-cost[i];
             current_value += gas[i]-cost[i];
            if(current_value < 0){
                current_value = 0;
                gas_station = i+1;
            }
        }
        return total_value >=0 ? gas_station : -1;
      
    }
};