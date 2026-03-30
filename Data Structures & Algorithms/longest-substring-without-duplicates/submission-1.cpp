#include <bits/stdc++.h>
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()==0)
        return 0;
        int l = 0;
        int r = 0;
        int n = s.size();
        unordered_map<char,int> see;
        int answer = 1;
        while(r<n){
            if(see.find(s[r]) != see.end()){
                if(see[s[r]]>=1){
                    see[s[l]]--;
                    l++;
                }else{
                    see[s[r]]++;
                    answer = max(answer,r-l+1);
                    r++;

                }
            }else{
                see[s[r]]++;
               answer = max(answer,r-l+1);
               r++;
            }
        }
        return answer = max(answer,r-l);
    }
};
