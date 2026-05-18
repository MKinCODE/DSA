#include<iostream>
#include<vector>
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
    vector<int> preorderTraversal(TreeNode* root) {
        if(root==nullptr) return{};
        vector<int> ans;
        vector<int> leftp;
        vector<int> rightp;
        ans.push_back(root->val);
        leftp=preorderTraversal(root->left);
        rightp=preorderTraversal(root->right);
        ans.insert(ans.end(),leftp.begin(),leftp.end());
        ans.insert(ans.end(),rightp.begin(),rightp.end());
        return ans;

    }
};