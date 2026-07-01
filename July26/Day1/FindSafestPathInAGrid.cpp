// LEETCODE 2812. Find the Safest Path in a Grid


// Time complexity: O(n²logn)
// Space complexity: O(n²)


class Solution {
private:
    vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    bool isValidCell(vector<vector<int>>& grid , int i , int j) {
        int n = grid.size();
        return i >= 0 && i < n && j >= 0 && j < n;
    }

    bool isValidSafe(vector<vector<int>>& grid , int minSafeness) {
        int n = grid.size();

        if (grid[0][0] < minSafeness || grid[n - 1][n - 1] < minSafeness) {
            return false;
        }

        queue<pair<int , int>> q;
        vector<vector<bool>> vis(n , vector<bool>(n , false));
        q.push({0 , 0});
        vis[0][0] = true;

        while(!q.empty()) {
            auto curr = q.front();
            q.pop();

            if (curr.first == n - 1 && curr.second == n - 1) {
                return true;
            }

            for (auto& d : dir) {
                int di = curr.first + d[0];
                int dj = curr.second + d[1];

                if (isValidCell(grid , di , dj) && !vis[di][dj] && grid[di][dj] >= minSafeness) {
                    vis[di][dj] = true;
                    q.push({di , dj});
                }
            }
        }

        return false;
    }

public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<pair<int , int>> q;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    q.push({i , j});
                    grid[i][j] = 0;
                }
                else {
                    grid[i][j] = -1;
                }
            }
        }

        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                auto curr = q.front();
                q.pop();

                for (auto& d : dir) {
                    int di = curr.first + d[0];
                    int dj = curr.second + d[1];
                    int val = grid[curr.first][curr.second];

                    if (isValidCell(grid , di , dj) && grid[di][dj] == -1) {
                        grid[di][dj] = val + 1;
                        q.push({di , dj});
                    }
                }
            }
        }

        int st = 0;
        int end = 0;
        int res = -1;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                end = max(end , grid[i][j]);
            }
        }

        while(st <= end) {
            int mid = st + (end - st) / 2;
            if (isValidSafe(grid , mid)) {
                res = mid;
                st = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }
        return res;
    }
};