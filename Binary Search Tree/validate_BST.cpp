 #include <climits>

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
    bool check(TreeNode* root, long long max, long long min){
        if (root==nullptr) return true;
        if (root->val<=min || root->val>=max) return false;
        return check(root->left,root->val,min) && check(root->right,max,root->val);
    }
    bool isValidBST(TreeNode* root) {
        long long max=LLONG_MAX;
        long long min=LLONG_MIN;
        return check(root,max,min);
    }
};