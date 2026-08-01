struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root==nullptr) return false;
        int target=targetSum-root->val;
        if(target==0 && root->left==nullptr && root->right==nullptr) return true;
        else{
        return hasPathSum(root->left,target)||hasPathSum(root->right,target);
        }
    }
};

//mine
class Solution {
public:
    bool dfs(TreeNode* root, int target, int sum){
        if(root==nullptr) return false;

        sum+=root->val;

        if(root->left==nullptr && root->right==nullptr && sum==target) return true;
        
        return dfs(root->left,target,sum) || dfs(root->right,target,sum);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==nullptr) return false;
        return dfs(root,targetSum,0);
    }
};