#include <vector>
#include <algorithm>
using namespace std;

//better approach: without using extra space
class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int maxi=*max_element(costs.begin(),costs.end());
        vector<int> freq(maxi+1, 0);

        for(int x:costs) freq[x]++;

        int ans=0;
        for(int i=1; i<=maxi; i++){
            if(i>coins) break;
            while(freq[i]>0 && coins>=i){
                coins-=i;
                freq[i]--;
                ans++;
            }
        }
        return ans;
    }
};
//less optimal approach: using extra space
class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        vector<int> freq(100001, 0);
        for(int x:costs) freq[x]++;
        int idx=0;
        for(int i=1; i<=100000; i++){
            while(freq[i]--){
                costs[idx++]=i;
            }
        }
        int i=0;
        int ans=0;
        while(i<costs.size()){
            if(coins<costs[i]) break;
            coins-=costs[i];
            ans++;
            i++;
        }
        return ans;
    }
};