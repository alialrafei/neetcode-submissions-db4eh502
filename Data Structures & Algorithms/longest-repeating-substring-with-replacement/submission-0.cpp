class Solution {
public:
    int characterReplacement(string s, int k) {
       vector<int> freq(26,0);
       int start = 0;
       int maxFreq = 0;
       int maxLen = 0;
       int n = s.size();
       for(int end = 0; end < n; end ++){
        int curIndex = s[end]-'A';
        freq[curIndex] ++;
        maxFreq = max(maxFreq,freq[curIndex]);
        while((end-start+1)-maxFreq>k){
            curIndex = s[start]-'A';
            freq[curIndex]--;
            start ++;
        }
        maxLen = max(maxLen,end-start+1);
       }
       return maxLen;
    }
};
