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
    void flatten(TreeNode* root) {
        if(root==nullptr) return;

        if(root->left!=nullptr){
            TreeNode* temp = root->left;

            while(temp->right!=nullptr) temp=temp->right;

            temp->right=root->right;
            root->right=root->left;
            root->left=nullptr;
        }
        flatten(root->right);

    }
};

//my first approach (not suitable acc to q)
class Solution {
    vector<int> preorder;
    int idx = 1;
    bool flag=false;
public:
    void dfs(TreeNode* root){
        if(root==nullptr) return;

        preorder.push_back(root->val);
        dfs(root->left);
        dfs(root->right);

    }
    void flatten(TreeNode* root) {
        if(root==nullptr) return;
        if(!flag){
            dfs(root);
            flag=true;
        }

        if(idx==preorder.size()) return;
        root->left=nullptr;
        TreeNode* temp = new TreeNode(preorder[idx++]);
        root->right=temp;
        flatten(root->right);
        return ;
    }
};