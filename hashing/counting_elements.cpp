#include<iostream>
#include<unordered_set>
#include<vector>
using namespace std;
class Solution{
    public:
    int countingelements(vector<int>& arr){
        unordered_set<int> us;
        int count=0;
        int n=arr.size();
        for(int i=0;i<n;i++){
            us.insert(arr[i]);
        }
        for(int i=0;i<n;i++){
            if(us.find(arr[i]+1)!=us.end()){
                count++;
            }
        }
        return count;
    }
};
