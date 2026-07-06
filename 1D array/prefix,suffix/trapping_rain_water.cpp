#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int> right(n);
        vector<int> left(n);
        int maxi=0;
        for(int i=n-1; i>=0; i--){
            maxi=max(maxi,height[i]);
            right[i]=maxi;
        }
        maxi=0;
        for(int i=0; i<n; i++){
            maxi=max(maxi,height[i]);
            left[i]=maxi;
        }
        int ans=0;
        for(int idx=0; idx<n; idx++){
            ans+=(min(right[idx],left[idx])-height[idx]);
        }
        return ans;
    }
};


//more optimal two pointer:-