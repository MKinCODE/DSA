#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
    
    int idx=0;
public:
    void dfs(TreeNode* root, string& ser){
        if(root==nullptr){
            ser+="#,";
        }
        else{
        ser+=to_string(root->val)+',';
        dfs(root->left,ser);
        dfs(root->right,ser);
        }
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ser="";
        dfs(root,ser);
        return ser;
    }
    TreeNode* deshelp(vector<string>& tokens){
        string token = tokens[idx++];

        if(token=="#") return nullptr;

        TreeNode* root = new TreeNode(stoi(token));

        root->left=deshelp(tokens);
        root->right=deshelp(tokens);

        return root;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> tokens;
        stringstream ss(data);
        string token;
        while(getline(ss,token,',')){
            tokens.push_back(token);
        }
        idx=0;
        return deshelp(tokens);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));