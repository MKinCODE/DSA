1class Solution {
2public:
3    int find(int x, vector<int>& parent){
4        if(parent[x]==x) return x;
5
6        return parent[x]=find(parent[x],parent);
7    }
8    void unionfn(int a, int b, vector<int>& parent){
9        int rootA = find(a,parent);
10        int rootB = find(b,parent);
11        if(rootA!=rootB)
12            parent[rootB]=rootA;
13    }
14    int makeConnected(int n, vector<vector<int>>& connections) {
15        vector<int> parent(n);
16        for(int i=0; i<n;i++) parent[i]=i;
17        int count=0;
18        int components = n;
19        for(auto connection:connections){
20            int u = connection[0];
21            int v = connection[1];
22
23            if(find(u,parent)==find(v,parent)) count++;
24            else{
25                unionfn(u,v,parent);
26                components--;
27            }
28        }
29        components--;
30        
31        if(components==0) return 0;
32        if(count<components) return -1;
33        return components;
34    }
35};