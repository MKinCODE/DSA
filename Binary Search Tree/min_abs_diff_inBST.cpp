#include<iostream>
#include<vector>
#include<algorithm>
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
public:
    int getMinimumDifference(TreeNode* root) {
        vector<int> ans;
        inorder(root,ans);
        int mini=__INT_MAX__;
        for(int i=1;i<ans.size();i++){
            mini=min(mini,abs(ans[i-1]-ans[i]));
        }
        return mini;
    }
    void inorder(TreeNode* root, vector<int>& ans){
        if(root==nullptr) return;
        inorder(root->left,ans);
        ans.push_back(root->val);
        inorder(root->right,ans);
    }
};