#include<queue>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
//using dfs as outer traversal
class Solution {
    int count=0;
public:
    void dfs(TreeNode* root, long long targetSum){
        if(root==nullptr) return;

        targetSum-=root->val;

        if(targetSum==0) count++;

        dfs(root->left,targetSum);
        dfs(root->right,targetSum);
    }
    int pathSum(TreeNode* root, int targetSum) {
        if(root==nullptr) return 0;
        
        dfs(root,targetSum);
        pathSum(root->left,targetSum);
        pathSum(root->right, targetSum);
        
        return count;

    }
};

//using bfs as outer traversal
class Solution {
    int count=0;
public:
    void dfs(TreeNode* root, long long targetSum){
        if(root==nullptr) return;

        targetSum-=root->val;

        if(targetSum==0) count++;

        dfs(root->left,targetSum);
        dfs(root->right,targetSum);
    }
    int pathSum(TreeNode* root, int targetSum) {
        if(root==nullptr) return 0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* temp=q.front();
            q.pop();
            dfs(temp,targetSum);
            if(temp->left!=nullptr) q.push(temp->left);
            if(temp->right!=nullptr) q.push(temp->right);
        }
        return count;
    }
};