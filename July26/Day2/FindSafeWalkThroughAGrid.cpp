// LEETCODE 3286. Find a Safe Walk Through a Grid

// Time complexity: O(mn)
// Space complexity: O(mn)



class Solution {
public:
    static constexpr int dirs[4][2] = {{0, 1} , {0, -1} , {1, 0} , {-1, 0}};

    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dist(m , vector<int>(n , INT_MAX));
        deque<pair<int , int>> dq;

        dq.emplace_front(0 , 0);
        dist[0][0] = grid[0][0];

        while(!dq.empty()) {
            auto [cx , cy] = dq.front();
            dq.pop_front();

            if (cx == m - 1 && cy == n - 1) {
                return true;
            }

            for (auto& [dx , dy] : dirs) {
                int nx = cx + dx;
                int ny = cy + dy;

                if (nx < 0 || nx >= m || ny < 0 || ny >= n) {
                    continue;
                }

                int cst = dist[cx][cy] + grid[nx][ny];
                if (cst >= health) {
                    continue;
                }

                if (cst < dist[nx][ny]) {
                    dist[nx][ny] = cst;
                    if (grid[nx][ny] == 0) {
                        dq.emplace_front(nx , ny);
                    }
                    else {
                        dq.emplace_back(nx , ny);
                    }
                }
            }
        }    

        return false;
    }
};