#include <sstream>
class Solution {
public:

    string encode(vector<string>& strs) {
        string answer = "";
        ostringstream stringBuilder;
        for(string s:strs){
            int n = s.size();
            stringBuilder << "#" <<to_string(n) << "@" << s;
        }
        answer = stringBuilder.str();
        cout<<answer<<endl;
        return answer;
    }

    vector<string> decode(string s) {
        int n = s.size();
        vector<string> result;
        int idx = 0;
        while( idx < n){
            if(s[idx]=='#'){
                idx = idx+1;
                int len = 0;
                int mult = 1;
                while(idx<n && s[idx]>='0' && s[idx]<='9'){
                    len = len*mult + (s[idx]-'0');
                    idx++;
                    mult*=10;
                }
                string decoded;
                idx = idx+1;
                while(idx<n && len>0){
                    decoded += s[idx] ;
                    idx++;
                    len--;
                }
                result.push_back(decoded);
            }else{
                idx++;
            }
            
        }
        return result;
    }
};
