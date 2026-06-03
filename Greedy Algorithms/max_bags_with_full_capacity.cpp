#include <bits/stdc++.h>
using namespace std;
//space optimized solution:
class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int k) {
        int n = capacity.size();
        int i;
        for(i=0; i<n; i++){
            capacity[i]=capacity[i]-rocks[i];
        }
        sort(capacity.begin(),capacity.end());
        int ans=0;
        for(int x:capacity){
            if(x>k) break;
            k-=x;
            ans++;
        }
        return ans;
    }
};
//first thought approach:
class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int k) {
        int n = capacity.size();
        vector<int> need(n);
        int i;
        for(i=0; i<n; i++){
            need[i]=capacity[i]-rocks[i];
        }
        sort(need.begin(),need.end());
        int ans=0;
        for(int x:need){
            if(x>k) break;
            k-=x;
            ans++;
        }
        return ans;
    }
};