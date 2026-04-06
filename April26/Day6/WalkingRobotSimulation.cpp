// LEETCODE 874. Walking Robot Simulation

// A robot on an infinite XY-plane starts at point (0, 0) facing north. The robot receives an array of integers commands, which represents a sequence of moves that it needs to execute. There are only three possible types of instructions the robot can receive:

// -2: Turn left 90 degrees.
// -1: Turn right 90 degrees.
// 1 <= k <= 9: Move forward k units, one unit at a time.
// Some of the grid squares are obstacles. The ith obstacle is at grid point obstacles[i] = (xi, yi). If the robot runs into an obstacle, it will stay in its current location (on the block adjacent to the obstacle) and move onto the next command.

// Return the maximum squared Euclidean distance that the robot reaches at any point in its path (i.e. if the distance is 5, return 25).

// Note:

// There can be an obstacle at (0, 0). If this happens, the robot will ignore the obstacle until it has moved off the origin. However, it will be unable to return to (0, 0) due to the obstacle.
// North means +Y direction.
// East means +X direction.
// South means -Y direction.
// West means -X direction.
 

// Example 1:

// Input: commands = [4,-1,3], obstacles = []

// Output: 25

// Explanation:

// The robot starts at (0, 0):

// Move north 4 units to (0, 4).
// Turn right.
// Move east 3 units to (3, 4).
// The furthest point the robot ever gets from the origin is (3, 4), which squared is 32 + 42 = 25 units away.

// Example 2:

// Input: commands = [4,-1,4,-2,4], obstacles = [[2,4]]

// Output: 65

// Explanation:

// The robot starts at (0, 0):

// Move north 4 units to (0, 4).
// Turn right.
// Move east 1 unit and get blocked by the obstacle at (2, 4), robot is at (1, 4).
// Turn left.
// Move north 4 units to (1, 8).
// The furthest point the robot ever gets from the origin is (1, 8), which squared is 12 + 82 = 65 units away.

// Example 3:

// Input: commands = [6,-1,-1,6], obstacles = [[0,0]]

// Output: 36

// Explanation:

// The robot starts at (0, 0):

// Move north 6 units to (0, 6).
// Turn right.
// Turn right.
// Move south 5 units and get blocked by the obstacle at (0,0), robot is at (0, 1).
// The furthest point the robot ever gets from the origin is (0, 6), which squared is 62 = 36 units away.

 

// Constraints:

// 1 <= commands.length <= 104
// commands[i] is either -2, -1, or an integer in the range [1, 9].
// 0 <= obstacles.length <= 104
// -3 * 104 <= xi, yi <= 3 * 104
// The answer is guaranteed to be less than 231.


// 🚀 Approach
// Obstacle storage:
//     Store obstacles in a hash set for O(1) lookup.
//     Use a string key like "x,y" to represent coordinates.
// Direction handling:
//     Represent the current direction as a vector (dx, dy).
//     Turning left (-2) rotates the vector 90° counter‑clockwise.
//     Turning right (-1) rotates the vector 90° clockwise.
// Movement simulation:
//     For each forward command, move step by step.
//     Before moving, check if the next cell is an obstacle. If yes, stop.
//     Otherwise, update the robot’s position.
// Distance tracking:
//     After each command, compute squared distance x * x + y * y.
//     Keep track of the maximum value.

// 🕛 Complexity
// Time complexity: O(m + n * maxVal)
// m = size of obstacle
// n = size of commands , maxVal = maximum value of commands

// Space complexity: O(m)




class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_set<string> st;
        for (vector<int>& obs : obstacles) {
            string key = to_string(obs[0]) + "," + to_string(obs[1]);
            st.insert(key);
        }

        int x = 0;
        int y = 0;
        int maxSqDist = 0;

        pair<int , int> dir = {0 , 1};
        for (int i = 0; i < commands.size(); i++) {
            if (commands[i] == -2) {
                dir = {-dir.second , dir.first};
            }
            else if (commands[i] == -1) {
                dir = {dir.second , -dir.first};
            }
            else {
                for (int s = 0; s < commands[i]; s++) {
                    int nx = x + dir.first;
                    int ny = y + dir.second;

                    string nxtKey = to_string(nx) + "," + to_string(ny);

                    if (st.find(nxtKey) != st.end()) {
                        break;
                    }

                    x = nx;
                    y = ny;
                }
            }

            maxSqDist = max(maxSqDist , x * x + y * y);
        }
        return maxSqDist;
    }
};