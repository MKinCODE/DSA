#include <vector>
#include <queue>
using namespace std;
//the first thought using min heap:
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        int m=points.size();
        int dist;
        int x,y;
        for(int i=0; i<m; i++){
            x=points[i][0];
            y=points[i][1];
            dist = (x*x + y*y);
            pq.push({dist,i});
        }
        vector<vector<int>> ans;
        while(k--){
            ans.push_back(points[pq.top().second]);
            pq.pop();
        }
        return ans;
    }
};
//since we only need k closest points, we can use max heap to store k closest points:
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,int>> pq;
        int m=points.size();
        int dist;
        int x,y;
        for(int i=0; i<m; i++){
            x=points[i][0];
            y=points[i][1];
            dist = (x*x + y*y);
            pq.push({dist,i});
            if(pq.size()>k) pq.pop();
        }
        vector<vector<int>> ans;
        while(k--){
            ans.push_back(points[pq.top().second]);
            pq.pop();
        }
        return ans;
    }
};