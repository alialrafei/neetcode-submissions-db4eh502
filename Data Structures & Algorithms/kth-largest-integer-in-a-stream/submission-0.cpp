class KthLargest {
private:
    int k_;
     priority_queue<int,vector<int>,greater<int>> top_k_score;
    multiset<int> remaing_scores;

public:
    KthLargest(int k, vector<int>& nums) {
        k_ = k;
        sort(nums.begin(),nums.end(),greater<>());
        int n = nums.size();
        for (int i = 0; i < min(k, n); i++) {
            top_k_score.push(nums[i]);
        }
        for (int i = k; i < n; i++) {
            remaing_scores.insert(nums[i]);
        }
    }

    int add(int val) {
        if (top_k_score.size() < k_ ) {
            top_k_score.push(val);
        } else if (top_k_score.size() == k_) {
            if(top_k_score.top() < val){
                remaing_scores.insert(top_k_score.top());
                top_k_score.pop();
                top_k_score.push(val);
            }else{
                 remaing_scores.insert(val);
            }

           
        }
        return top_k_score.top();
    }
    // in case of removal we can balance the top_k with the multiset
};
