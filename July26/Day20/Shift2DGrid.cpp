// LEETCODE 1260. Shift 2D Grid

// Time Complexity: O(m * n)
// Space Complexity: O(k)



class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        queue<int> q;

        k %= (n * m);
        int idx = (n * m) - k;

        for (int l = 0; l < k; l++) {
            int i = idx / n;
            int j = idx % n;

            q.push(grid[i][j]);
            idx++;
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                q.push(grid[i][j]);
                grid[i][j] = q.front();
                q.pop();
            }
        }

        return grid;
    }
};