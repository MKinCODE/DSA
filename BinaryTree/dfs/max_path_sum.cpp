#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    int sum=INT_MIN;
public:
    int dfs(TreeNode* root){
        if(root==nullptr) return 0;

        int left = dfs(root->left);
        int right = dfs(root->right);
        sum=max(sum,max(0,left)+max(0,right)+root->val);

        return root->val+max(0,max(left,right));
    }
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return sum;
    }
};