1class Solution {
2public:
3    int find(int x, vector<int>& parent){
4        if(parent[x]==x) return x;
5        return find(parent[x],parent);
6    }
7    void unionfn(int a, int b,vector<int>& parent){
8        int rootA = find(a,parent);
9        int rootB = find(b,parent);
10        if(rootA!=rootB){
11            parent[rootB]=rootA;
12        }
13    }
14    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
15        int n = edges.size();
16        
17        vector<int> parent(n+1);
18        for(int i=1; i<=n;i++){
19            parent[i]=i;
20        }
21        vector<int> ans;
22        for(auto edge:edges){
23            int u=edge[0];
24            int v=edge[1];
25
26            if(find(u,parent)==find(v,parent)) ans=edge;
27            else{
28                unionfn(u,v,parent);
29            }
30        }
31        return ans;
32    }
33};