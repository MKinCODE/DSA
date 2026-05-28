#include<vector>
using namespace std;
class Solution {
public:
    void solver(int city, vector<vector<int>>& isConnected, vector<int>& visited){
        visited[city]=1;
        for(int j=0; j<isConnected.size();j++){
            if(isConnected[city][j]==1 && !visited[j]) solver(j,isConnected,visited); 
        }
        return;
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int rows=isConnected.size();
        vector<int> visited(rows,0);
        int province=0;
        for(int node=0;node<rows;node++){
            if(!visited[node]) {
                province++;
                solver(node,isConnected,visited);
            }
        }
        return province;
    }
};