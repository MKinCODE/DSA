#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;
//not optimised approach
class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int,int> losses;
        vector<vector<int>> answer(2);
        for(int i=0;i<matches.size();i++){
            int lose=matches[i][1];
            int wine=matches[i][0];
            losses[lose]++;
            if(losses.find(wine)==losses.end()){
                losses[wine]=0;
            }
        }
        
        for(auto it : losses){
            if(it.second==0){
                answer[0].push_back(it.first);
            }
            else if(it.second==1){
                answer[1].push_back(it.first);
            }
        }
        sort(answer[0].begin(),answer[0].end());
        sort(answer[1].begin(),answer[1].end());
    return answer;
    }
};