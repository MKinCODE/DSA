#include<unordered_map>
using namespace std;
class Solution {
public:
    int digitFrequencyScore(int n) {
        unordered_map<int,int> umap;
        int sum=0;
        int x=n;
        while(x!=0){
            int digit=x%10;
            umap[digit]++;
            x/=10;
        }
        for(auto it:umap){
            int d=it.first;
            int freq=it.second;
            sum+=d*freq;
        }
        return sum;
    }
};