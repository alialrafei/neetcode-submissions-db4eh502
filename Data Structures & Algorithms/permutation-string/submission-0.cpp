class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> freqMain(26,0);
        vector<int> freq(26,0);
        if(s2.size() < s1.size())
            return false;
        for(char c:s1){
            freq[c-'a']++;
        }
        int start = 0 ; 
        int end = 0;
        
        int n = s2.size();
        int m = s1.size();
        while(end<n){
            freqMain[s2[end]-'a']++;
            if((end-start+1)==m){
                 
                bool yes = true;
                for(int i =0;i < 26;i++){
                    if(freq[i]!=freqMain[i]){
                        yes = false;
                        break;
                    }
                }
                if(yes)
                    return true;
                freqMain[s2[start]-'a']--;
                start++;
            }
            end++;
        }
        if((end-start+1)==m){
           
                bool yes = true;
                for(int i =0;i < 26;i++){
                    if(freq[i]!=freqMain[i]){
                        yes = false;
                        break;
                    }
                }
                if(yes)
                    return true;
        }
        return false;
    }
};
