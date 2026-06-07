#include<vector>
#include<string>
using namespace std;

class Solution {
private:
    vector<string> result;
public:
    void recurse(string& path, int n, int open_count, int close_count){
        if(path.size()==2*n){
            result.push_back(path);
            return;
        }
        if(open_count<n){
            path+='(';
            recurse(path,n,open_count + 1,close_count);
            path.pop_back();
        }
        if(close_count<open_count){
            path+=')';
            recurse(path,n,open_count,close_count + 1);
            path.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        string path="";
        recurse(path,n,0,0);
        return result;
    }
};