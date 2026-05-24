class Solution {
private:
  
    bool Dfs(TreeNode* root, int& height) {   
        if (root == NULL) {
            height = -1;
            return true;
        }
        int left, right;
        if (Dfs(root->left, left) &&
            Dfs(root->right, right) && abs(left - right) < 2) {
            height = max(left, right) + 1;
            return true;
        }
        return false;
    }

public:
    bool isBalanced(TreeNode* root) {
        int height;
        return Dfs(root, height);
    }
};

