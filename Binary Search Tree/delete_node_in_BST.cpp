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
    TreeNode* getsuccessor(TreeNode* curr){
        curr=curr->right;
        while( curr->left!=nullptr){
            curr=curr->left;
        }
        return curr;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        //0 or 1 child
        if(root==nullptr) return root;
        if(key<root->val){
            root->left=deleteNode(root->left,key);
        }
        else if(key>root->val){
            root->right=deleteNode(root->right,key);
        }
        else{
            if(root->left==nullptr){
                TreeNode* temp=root->right;
                delete root;
                return temp;
            }
            if(root->right==nullptr){
                TreeNode* temp=root->left;
                delete root;
                return temp;
            }

            //2 child 
            TreeNode* succ=getsuccessor(root); //get the smallest greater element of key
            root->val=succ->val;               //create duplicate
            root->right=deleteNode(root->right,succ->val); //delete duplicate which is now leaf(0 or 1 child)
        }
        return root;
    }
};