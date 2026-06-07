#include<vector>
using namespace std;
class Solution {
private:
    vector<vector<int>> result;
public:
    void backtrack(int node, vector<int>& path, vector<vector<int>>& graph, int target){
        if(node==target){
            result.push_back(path);
            return;
        }
        for(auto neighbour:graph[node]){
            path.push_back(neighbour);
            backtrack(neighbour,path,graph,target);
            path.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int target=graph.size()-1;
        vector<int> path;
        path.push_back(0);
        backtrack(0,path,graph,target);
        return result;
    }
};