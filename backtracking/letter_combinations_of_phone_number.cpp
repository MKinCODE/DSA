#include<vector>
#include<string>
using namespace std;
//most optimal using loops
class Solution {
public:

    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};
        vector<string> mapping={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        string path="";
        vector<string> result={""};
        for(char c:digits){
            vector<string> temp;
            for(string s:result){
                for(char a:mapping[c-'0']){
                    temp.push_back(s+a);
                }
            }
            result=temp;
        }
        return result;
    }
};
//less optimal but recursion used
class Solution {
    private:
    vector<string> result;
public:
    void helper(int index, string& path, const string& digits, const vector<string>& mapping){
        if(path.length()==digits.length()){
            result.push_back(path);
            return;
        }
        string letter=mapping[digits[index]-'0'];
        for(char c:letter){
            path+=c;
            helper(index+1,path,digits,mapping);
            path.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};
        vector<string> mapping={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        string path="";
        helper(0,path,digits,mapping);
        return result;
    }
};