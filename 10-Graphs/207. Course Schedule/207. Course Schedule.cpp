1class Solution {
2public:
3    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
4        int count=0;
5        vector<vector<int>> adj(numCourses);
6        for(int i=0; i<prerequisites.size(); i++){
7            int u = prerequisites[i][0];
8            int v = prerequisites[i][1];
9            adj[v].push_back(u);
10        }
11        vector<int> indegree(numCourses,0);
12        for(int u=0; u<numCourses; u++){
13            for(int v:adj[u]){
14                indegree[v]++;
15            }
16        }
17        queue<int> q;
18        for(int i=0; i<numCourses; i++){
19            if(indegree[i]==0){
20                q.push(i);
21                count++;
22            }
23        }
24        if(count==0) return false;
25        while(!q.empty()){
26            int f = q.front();
27            q.pop();
28
29            for(int neighbour: adj[f]){
30                indegree[neighbour]--;
31                if(indegree[neighbour]==0){
32                    q.push(neighbour);
33                    count++;
34                }
35            }
36        }
37        if(count==numCourses) return true;
38        return false;
39    }
40};