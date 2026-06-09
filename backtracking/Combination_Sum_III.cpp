#include<vector>
using namespace std;
class Solution {
private:
    vector<vector<int>> result;
public:
    void recurse(vector<int>& ans, int k, int& sum, int n, int index){
        if(ans.size()==k){
            if(sum==n){
                result.push_back(ans);
                return;
            }
            else return;   
        }
        for(int i=index; i<=9; i++){
            if(sum+i>n) break;
            ans.push_back(i);
            sum+=i;
            recurse(ans,k,sum,n,i+1);
            sum-=i;
            ans.pop_back(); 
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        int sum=0;
        vector<int> ans;
        recurse(ans,k,sum,n,1);
        return result;
    }
};