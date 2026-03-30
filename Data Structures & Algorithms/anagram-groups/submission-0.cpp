class Solution {
public:
    
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        vector<pair<long long,int>>hashes(n); // we can reduce time by using hashmap of hash and vector 
        for(int i =0;i<n;i++)
            hashes[i] = {computeHash(strs[i]),i};

        sort(hashes.begin(),hashes.end());
        vector<vector<string>> groups;

        for(int i = 0; i < n ; i ++ ){
            int idx = hashes[i].second;
            if(i==0 || hashes[i].first != hashes[i-1].first)
                groups.emplace_back();
            groups.back().push_back(strs[idx]);
        }
        return groups;
    }
private:
    long long computeHash(string  s){
        const int p = 31;
        const int mod= (int)1e9+9;
        long long hashValue = 0;
        sort(s.begin(),s.end());
        long long pow = 1;
        for(char c:s){
            hashValue = (hashValue+(c-'a'+1) *pow)%mod;
            pow = (pow*p)%mod;
        }
        return hashValue ;
    }
};