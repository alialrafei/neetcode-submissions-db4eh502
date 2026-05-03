class Solution {
public:
    struct Unionfind{
        unordered_map<int,int> parent;
        unordered_map<int,int> rank;
        Unionfind(vector<int> nums){
            int n = nums.size();
            for(int i = 0 ; i < n ; i ++){
                int node = nums[i];
                parent[node] = node;
                rank[node] = 0;
            }
        }
        int find(int node){
            if(parent[node]!=node)
                parent[node] = find(parent[node]);
            return parent[node];
        }
        void merge(int nodeA,int nodeB){
            int parentNodeA = find(nodeA);
            int parentNodeB = find(nodeB);

            if(parentNodeA!=parentNodeB){
                if(rank[parentNodeB] > rank[parentNodeA]){
                    parent[parentNodeA] = parentNodeB;
                } else if(rank[parentNodeA] > rank[parentNodeB]){
                    parent[parentNodeB] = parentNodeA;
                }else{
                    parent[parentNodeB] = parentNodeA;
                    rank[parentNodeA]++;
                }
            }
        }
        
    };
    int longestConsecutive(vector<int>& nums) {
        Unionfind sequence(nums);
        unordered_map<int,int> visited;
        unordered_map<int,int> count;
        int n = nums.size();
        for(int i =0 ; i < n ; i++){
            if(visited.find(nums[i]-1)!=visited.end()){
                sequence.merge(nums[i],nums[i]-1);
            }
            if(visited.find(nums[i]+1)!=visited.end()){
                sequence.merge(nums[i],nums[i]+1);
            }
            visited[nums[i]]=0;
        }
        int answer = 0;
        visited.clear();
        for(int i =0; i < n ; i ++ ){
            if(visited.find(nums[i])!=visited.end())
                continue;
            visited[nums[i]] = 1;
            int parent = sequence.find(nums[i]);
            int rank =++count[parent];
            answer = max(answer,rank);
        }
        return answer;
    }
};
