class Solution {
public:
    bool isPalindrome(string s) {
         string result;
        int n = s.size();
        for(int i =0;i<n;i++){
            if(s[i]>='a' && s[i]<='z'){
                 result += s[i];
            }else if(s[i]>='A' && s[i]<='Z'){
                result += s[i]+32;
            }else if(s[i]>='0' && s[i]<='9'){
                result += s[i];
            }
        }
        int st = 0;
        int ed = result.size()-1;
        
        while(st<=ed && result[st]==result[ed]){
            st++;
            ed--;
        }
       
        return st > ed;
    }
};
