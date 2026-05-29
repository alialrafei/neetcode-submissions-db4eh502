class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        unordered_map<int, int> change;
        int n = bills.size();
        for (int i = 0; i < n; i++) {
            if (bills[i] > 5) {
                int orignal_bill = bills[i];
                bills[i] -= 5;
                int tens = bills[i] / 10;
                if (change[10] >= tens) {
                    change[10] -= tens;
                    bills[i] -= tens * 10;
                }
                int fives = bills[i] / 5;
                if (change[5] >= fives) {
                    change[5] -= fives;
                    bills[i] -= fives * 5;
                } else {
                    return false;
                }
                change[orignal_bill]++;
                continue;
            }
            change[bills[i]]++;
        }
        return true;
    }
};