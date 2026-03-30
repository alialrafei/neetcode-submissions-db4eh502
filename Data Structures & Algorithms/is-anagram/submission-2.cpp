class Solution {
public:
    static const int N = 27;
    bool isAnagram(string s, string t) {
        int freq[N]={0};
        if(s.size()!=t.size())
            return false;
        for(int i =0;i < s.size();i++){
            freq[s[i]-'a']++;
            freq[t[i]-'a']--;
        }
        for(int i =0;i<27;i++){
            if(freq[i]!=0)
                return false;
        }
        return true;
    }
};
