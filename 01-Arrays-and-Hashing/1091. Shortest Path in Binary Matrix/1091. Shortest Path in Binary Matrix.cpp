1class Solution {
2public:
3    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
4
5        int rows = grid.size();
6        int cols = grid[0].size();
7        if (grid[0][0] == 1 || grid[rows - 1][cols - 1] == 1)
8            return -1;
9        vector<vector<int>> dist(rows, vector<int>(cols, -1));
10        queue<pair<int, int>> q;
11        q.push({0, 0});
12        dist[0][0] = 1;
13
14        int drows[] = {-1, 1, 0, 0, -1, 1, -1, 1};
15        int dcols[] = {0, 0, -1, 1, -1, 1, 1, -1};
16        while (!q.empty()) {
17            auto [r, c] = q.front();
18            q.pop();
19            for (int k = 0; k < 8; k++) {
20                int nr = r + drows[k];
21                int nc = c + dcols[k];
22                if (nr >= 0 && nr < rows && nc >= 0 && nc < cols &&
23                    grid[nr][nc] == 0 && dist[nr][nc] == -1) {
24                    dist[nr][nc] = dist[r][c] + 1;
25                    q.push({nr, nc});
26                }
27            }
28        }
29        return dist[rows - 1][cols - 1];
30    }
31};