struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#include <utility>
using std::pair;

class Solution {
public:
    int tnode;
    int averageOfSubtree(TreeNode* root) {
        tnode=0;
        helper(root);
        return tnode;
    }
    pair<int,int> helper(TreeNode* root){
        if (root==nullptr) return {0,0};

        pair<int,int> left = helper(root->left);
        int leftSum = left.first;
        int leftCount = left.second;
        pair<int,int> right = helper(root->right);
        int rightSum = right.first;
        int rightCount = right.second;

        int totalSum = left.first + right.first + root->val;
        int totalCount = left.second + right.second + 1;
        int average = totalSum / totalCount;
        if(root->val==average) tnode++;

        return{totalSum,totalCount};
    }
};