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
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        TreeNode* righth;
        TreeNode* lefth;
        if(root==nullptr) return root;
        if(root->val<low){
            righth=trimBST(root->right,low,high);
            return righth;
        }
        else if(root->val>high){
            lefth=trimBST(root->left,low,high);
            return lefth;
        }
        else{
            lefth=trimBST(root->left,low,high);
            righth=trimBST(root->right,low,high);
        }
        root->left=lefth;
        root->right=righth;
        return root;
    }
};