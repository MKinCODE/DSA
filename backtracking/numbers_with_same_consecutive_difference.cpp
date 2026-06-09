#include<vector>
#include<string>
using namespace std;

class Solution {
private:
    vector<int> result;
public:
    void check(string& path, int n, int k){
        if(path.length()==n){
            result.push_back(stoi(path));
            return;
        }
        string nums;
        if(path.length()==0) nums="123456789";
        else{
            nums="0123456789";
        }
        for(char a:nums){
            path+=a;
            if(path.length()==1) check(path,n,k);
            else if(path.length()>=2 && abs(path[path.length()-1]-path[path.length()-2])==k) check(path,n,k);
            path.pop_back();
        }

    }
    vector<int> numsSameConsecDiff(int n, int k) {
        string path="";
        check(path,n,k);
        return result;
    }
};

//cleaner:
class Solution {
private:
    vector<int> result;
public:
    void helper(string& path, int n, int k){
        if(path.length()==n){
            result.push_back(stoi(path));
            return;
        }
        string nums;
        if(path.length()==0) nums="123456789";
        else nums="0123456789";

        for(char a:nums){
            path+=a;
            if(path.length()==1 || abs(path[path.length()-1]-path[path.length()-2])==k) helper(path,n,k);
            path.pop_back();
        }

    }
    vector<int> numsSameConsecDiff(int n, int k) {
        string path="";
        helper(path,n,k);
        return result;
    }
};