#include<string>
using namespace std;

class Trie {
private:
    struct TrieNode{
        TrieNode* children[26];
        bool isEnd;
        TrieNode(){
            for(int i=0; i<26;i++){
                children[i]=nullptr;
            }
            isEnd=false;
        }    
    };
    TrieNode* root;
public:
    Trie() {
        root=new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* curr = root;

        for(char ch : word) {
            int idx = ch - 'a';

            if(curr->children[idx] == nullptr) {
                curr->children[idx] = new TrieNode();
            }

            curr = curr->children[idx];
        }

        curr->isEnd = true;
    }
    
    bool search(string word) {
        TrieNode* curr = root;

        for(char ch : word) {
            int idx = ch - 'a';

            if(curr->children[idx] == nullptr) {
                return false;
            }

            curr = curr->children[idx];
        }

        return curr->isEnd;
    }
    
    bool startsWith(string prefix) {
        TrieNode* curr = root;

        for(char ch : prefix) {
            int idx = ch - 'a';

            if(curr->children[idx] == nullptr) {
                return false;
            }

            curr = curr->children[idx];
        }

        return true;
    }
};

