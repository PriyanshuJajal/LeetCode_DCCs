// LEETCODE 3661. Maximum Walls Destroyed by Robots

// There is an endless straight line populated with some robots and walls. You are given integer arrays robots, distance, and walls:
// robots[i] is the position of the ith robot.
// distance[i] is the maximum distance the ith robot's bullet can travel.
// walls[j] is the position of the jth wall.
// Every robot has one bullet that can either fire to the left or the right at most distance[i] meters.

// A bullet destroys every wall in its path that lies within its range. Robots are fixed obstacles: if a bullet hits another robot before reaching a wall, it immediately stops at that robot and cannot continue.

// Return the maximum number of unique walls that can be destroyed by the robots.

// Notes:

// A wall and a robot may share the same position; the wall can be destroyed by the robot at that position.
// Robots are not destroyed by bullets.
 

// Example 1:

// Input: robots = [4], distance = [3], walls = [1,10]

// Output: 1

// Explanation:

// robots[0] = 4 fires left with distance[0] = 3, covering [1, 4] and destroys walls[0] = 1.
// Thus, the answer is 1.
// Example 2:

// Input: robots = [10,2], distance = [5,1], walls = [5,2,7]

// Output: 3

// Explanation:

// robots[0] = 10 fires left with distance[0] = 5, covering [5, 10] and destroys walls[0] = 5 and walls[2] = 7.
// robots[1] = 2 fires left with distance[1] = 1, covering [1, 2] and destroys walls[1] = 2.
// Thus, the answer is 3.
// Example 3:
// Input: robots = [1,2], distance = [100,1], walls = [10]

// Output: 0

// Explanation:

// In this example, only robots[0] can reach the wall, but its shot to the right is blocked by robots[1]; thus the answer is 0.

 

// Constraints:

// 1 <= robots.length == distance.length <= 105
// 1 <= walls.length <= 105
// 1 <= robots[i], walls[j] <= 109
// 1 <= distance[i] <= 105
// All values in robots are unique
// All values in walls are unique
 

// Time Complexity: O(nlog(w) + nlogn + wlogw)
//     n = robots.size(), w = walls.size()
    
// Space Complexity : O(n)


class Solution {
public:
    typedef pair<int , int> P;
    vector<vector<int>> memo;

    int cntWalls(vector<int>& walls , int l , int r) {
        int lIdx = lower_bound(begin(walls) , end(walls) , l) - begin(walls);
        int rIdx = upper_bound(begin(walls) , end(walls) , r) - begin(walls);

        return rIdx - lIdx;
    }

    int solve(vector<int>& walls , vector<P>& robotDist , vector<P>& range , int i , int prevDir) {
        if (i == robotDist.size()) return 0;

        if (memo[i][prevDir] != -1) return memo[i][prevDir];

        int lSt = range[i].first;

        // Previous robot fired bullet towards right...
        if (prevDir == 1) {
            lSt = max(lSt , range[i - 1].second + 1);
        }

        int lTake = cntWalls(walls , lSt , robotDist[i].first) +
                    solve(walls , robotDist , range , i + 1 , 0);
            
        int rTake = cntWalls(walls , robotDist[i].first , range[i].second) +
                    solve(walls , robotDist , range , i + 1 , 1);

        return memo[i][prevDir] = max(lTake , rTake);
    }

    int maxWalls(vector<int>& robots, vector<int>& distance, vector<int>& walls) {
        int n = robots.size();
        vector<P> robotDist(n);

        for (int i = 0; i < n; i++) {
            robotDist[i] = {robots[i] , distance[i]};
        }

        sort(begin(robotDist) , end(robotDist));
        sort(begin(walls) , end(walls));

        vector<P> range(n);

        for (int i = 0; i < n; i++) {
            int pos = robotDist[i].first;
            int d = robotDist[i].second;

            int left = (i == 0) ? 1 : robotDist[i - 1].first + 1;
            int right = (i == n - 1) ? 1e9 : robotDist[i + 1].first - 1;

            int L = max(pos - d , left);
            int R = min(pos + d , right);

            range[i] = {L , R}; 
        }

        memo.assign(n + 1 , vector<int>(2 , -1));

        return solve(walls , robotDist , range , 0 , 0);
    }
};