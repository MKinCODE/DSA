
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
    int max=0;
    int sum=0;
    void dfs(TreeNode* root, int current){
        if(root==nullptr) return;

        if(current>max){
            max=current;
            sum=root->val;
        }
        else if(current==max){
            sum+=root->val;
        }
        dfs(root->left,current+1);
        dfs(root->right,current+1);
    }
    int deepestLeavesSum(TreeNode* root) {
       dfs(root,0);
       return sum;
    }
};