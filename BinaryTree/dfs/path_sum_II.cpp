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
    vector<vector<int>> ans;
public:
    void dfs(TreeNode* root, int targetSum, vector<int>& temp){
        if(root==nullptr) return;

        temp.push_back(root->val);
        targetSum-=root->val;
        if(root->left==nullptr && root->right==nullptr && targetSum==0){
            ans.push_back(temp);
        }
        else{
            dfs(root->left, targetSum,temp);
            dfs(root->right, targetSum, temp);
        }
        temp.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> temp;
        dfs(root,targetSum,temp);
        return ans;
    }
};