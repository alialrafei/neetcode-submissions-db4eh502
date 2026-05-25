class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> mp = {{'I', 1},   {'V', 5},   {'X', 10},
                                       {'L', 50},  {'C', 100}, {'D', 500},
                                       {'M', 1000}};
        unordered_map<string, int> special = {{"IV", 4},   {"IX", 9},
                                              {"XL", 40},  {"XC", 90},
                                              {"CD", 400}, {"CM", 900}};
        int answer = 0;
        int n = s.size();
        int idx = 0;
        while (idx < n) {
            if (idx + 1 < n && mp[s[idx]] < mp[s[idx + 1]]) {
                string spe  = s.substr(idx, 2);;
                answer += special[spe];
                idx += 2;
            } else {
                answer += mp[s[idx]];
                idx++;
            }
        }
        return answer;
    }

};