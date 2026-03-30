class UnionFind {
    unordered_map<int, int> parent;

public:
    UnionFind(vector<int> nums) { 
        for (int i = 0; i < nums.size(); i++) {
             parent[nums[i]] = nums[i];
        }
   

}
int find(int i) {
    if (parent[i] == i) {
        return i;
    }
    return parent[i] = find(parent[i]);
}
void unite(int i, int j) {
    int parentI = find(i);
    int parentJ = find(j);
    parent[parentI] = parentJ;
}};
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> mp;
        unordered_map<int,int>vist;
        UnionFind uf(nums);
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (mp.find(nums[i] - 1) != mp.end()) {
                uf.unite(nums[i] - 1, nums[i]);
            }
            if (mp.find(nums[i] + 1) != mp.end()) {
                uf.unite(nums[i] + 1, nums[i]);
            }
            mp[nums[i]] = 0;
        }
        int answer = 0;
        for (int i = 0; i < n; i++) {
            if(vist.find(nums[i])!=vist.end())
                continue;
            int parent = uf.find(nums[i]);
            vist[nums[i]]=1;
            mp[parent]++;
            answer = max(answer, mp[parent]);
        }
        return answer;
    }
};