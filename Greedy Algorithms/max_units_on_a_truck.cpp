#include <vector>
#include <algorithm>
using namespace std;
//optimal:
class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(),boxTypes.end(), [](vector<int>& a, vector<int>& b){
            return a[1]>b[1];
        });
        int i=0;
        int ans=0;
        int m;
        while(truckSize && i<boxTypes.size()){
            m = min(truckSize,boxTypes[i][0]);
            ans+=m*boxTypes[i][1];
            truckSize-=m;
            i++;
        }
        return ans;
    }
};
//first thought approach:
class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(),boxTypes.end(), [](vector<int>& a, vector<int>& b){
            return a[1]>b[1];
        });
        int i=0;
        int ans=0;
        int m;
        while(truckSize && i<boxTypes.size()){
            while(boxTypes[i][0]!=0 && truckSize){
                truckSize--;
                ans+=boxTypes[i][1];
                boxTypes[i][0]--;
            }
            i++;
        }
        return ans;
    }
};