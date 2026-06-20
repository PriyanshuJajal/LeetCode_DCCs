// LEETCODE 1840. Maximum Building Height

// You want to build n new buildings in a city. The new buildings will be built in a line and are labeled from 1 to n.

// However, there are city restrictions on the heights of the new buildings:

// The height of each building must be a non-negative integer.
// The height of the first building must be 0.
// The height difference between any two adjacent buildings cannot exceed 1.
// Additionally, there are city restrictions on the maximum height of specific buildings. These restrictions are given as a 2D integer array restrictions where restrictions[i] = [idi, maxHeighti] indicates that building idi must have a height less than or equal to maxHeighti.

// It is guaranteed that each building will appear at most once in restrictions, and building 1 will not be in restrictions.

// Return the maximum possible height of the tallest building.

 

// Example 1:


// Input: n = 5, restrictions = [[2,1],[4,1]]
// Output: 2
// Explanation: The green area in the image indicates the maximum allowed height for each building.
// We can build the buildings with heights [0,1,2,1,2], and the tallest building has a height of 2.
// Example 2:


// Input: n = 6, restrictions = []
// Output: 5
// Explanation: The green area in the image indicates the maximum allowed height for each building.
// We can build the buildings with heights [0,1,2,3,4,5], and the tallest building has a height of 5.
// Example 3:


// Input: n = 10, restrictions = [[5,3],[2,5],[7,4],[10,3]]
// Output: 5
// Explanation: The green area in the image indicates the maximum allowed height for each building.
// We can build the buildings with heights [0,1,2,3,3,4,4,5,4,3], and the tallest building has a height of 5.
 

// Constraints:

// 2 <= n <= 109
// 0 <= restrictions.length <= min(n - 1, 105)
// 2 <= idi <= n
// idi is unique.
// 0 <= maxHeighti <= 109


// Time Complexity: O(mlogm)
// Space Complexity: O(1)


class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {
        restrictions.push_back({1 , 0});
        sort(begin(restrictions) , end(restrictions));

        if (restrictions.back()[0] != n) {
            restrictions.push_back({n , n - 1});
        }

        int m = restrictions.size();

        for (int i = 1; i < m; i++) {
            int dist = restrictions[i][0] - restrictions[i - 1][0];
            restrictions[i][1] = min(restrictions[i][1] , restrictions[i - 1][1] + dist);
        }

        for (int i = m - 2; i >= 0; i--) {
            int dist = restrictions[i + 1][0] - restrictions[i][0];
            restrictions[i][1] = min(restrictions[i][1] , restrictions[i + 1][1] + dist);
        }

        long long maxHt = 0;
        for (int i = 1; i < m; i++) {
            long long x1 = restrictions[i - 1][0];
            long long h1 = restrictions[i - 1][1];

            long long x2 = restrictions[i][0];
            long long h2 = restrictions[i][1];

            long long d = x2 - x1;
            maxHt = max(maxHt , (h1 + h2 + d) / 2);
        }
        return (int)maxHt;
    }
};