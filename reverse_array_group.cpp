#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
  public:
    void reverseInGroups(vector<int> &arr, int k) {
        // code here
        int n=arr.size();
        
        if(k>n){
            reverse(arr.begin(),arr.end());
        }
        else{
            for(int i=0;i<n/k;i++){
                reverse(arr.begin()+k*i,arr.begin()+(k*(i+1)));
            }
            if(n%k!=0){
                reverse(arr.begin()+(k*(n/k)),arr.end());
            }
        }
    }
};
