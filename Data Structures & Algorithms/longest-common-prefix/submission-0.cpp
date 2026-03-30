class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        unordered_map<string,int> tree;
        for(string s:strs){
            string prefix = "";
            for(char c:s){
                prefix += c;
                tree[prefix]++;
            }
        }
        int n = strs.size();
        string result = "";
        int mxLen = 0;
        for(pair<string,int> node:tree){
            int count = node.second;
            int curLen = node.first.size();
            if(count==n){
                if(curLen>mxLen){
                    result = node.first;
                    mxLen = curLen;
                }
            }
        }
        return result;
    }
};