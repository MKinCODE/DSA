#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq(piles.begin(),piles.end());
        for(int i=0; i<k; i++){
            int n=pq.top();
            pq.pop();
            pq.push(n-(n/2));
        }
        int total=0;
        while(!pq.empty()){
            total+=pq.top();
            pq.pop();
        }
        return total;
    }
};