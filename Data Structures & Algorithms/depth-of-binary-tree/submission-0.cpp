class Solution {
public:
    int MaxDepth(TreeNode *root){
        if(root == NULL)
            return 0;
        int d_right = 0;
        if(root->right)
            d_right = 1+ MaxDepth(root->right);
        
        int d_left = 0;
        if(root->left)
             d_left = 1+ MaxDepth(root->left);

        return max(d_left,d_right);

    }
    int maxDepth(TreeNode* root) {
        if(root == NULL)
            return 0;
        return MaxDepth(root)+1;
    }
};