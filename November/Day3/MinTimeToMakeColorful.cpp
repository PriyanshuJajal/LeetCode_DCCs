// LEETCODE 1578. Minimum Time to Make Rope Colorful

// Alice has n balloons arranged on a rope. You are given a 0-indexed string colors where colors[i] is the color of the ith balloon.

// Alice wants the rope to be colorful. She does not want two consecutive balloons to be of the same color, so she asks Bob for help. Bob can remove some balloons from the rope to make it colorful. You are given a 0-indexed integer array neededTime where neededTime[i] is the time (in seconds) that Bob needs to remove the ith balloon from the rope.

// Return the minimum time Bob needs to make the rope colorful.

 

// Example 1:


// Input: colors = "abaac", neededTime = [1,2,3,4,5]
// Output: 3
// Explanation: In the above image, 'a' is blue, 'b' is red, and 'c' is green.
// Bob can remove the blue balloon at index 2. This takes 3 seconds.
// There are no longer two consecutive balloons of the same color. Total time = 3.
// Example 2:


// Input: colors = "abc", neededTime = [1,2,3]
// Output: 0
// Explanation: The rope is already colorful. Bob does not need to remove any balloons from the rope.
// Example 3:


// Input: colors = "aabaa", neededTime = [1,2,3,4,1]
// Output: 2
// Explanation: Bob will remove the balloons at indices 0 and 4. Each balloons takes 1 second to remove.
// There are no longer two consecutive balloons of the same color. Total time = 1 + 1 = 2.
 

// Constraints:

// n == colors.length == neededTime.length
// 1 <= n <= 105
// 1 <= neededTime[i] <= 104
// colors contains only lowercase English letters.





// 🚀 Approach
// Use two pointers: j tracks the last balloon kept, and i scans the current balloon.
// If colors[i] == colors[j], we have a conflict. Remove the one with the smaller neededTime, and keep the one with the larger neededTime for future comparisons.
// If the colors differ, move j to i and continue.
// Accumulate the total removal time in time.
// This greedy approach ensures we always keep the most expensive balloon in any group of duplicates, minimizing the total cost.



// 🕛 Complexity
// Time complexity: O(n)
// Space complexity: O(1)











class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.size();
        int time = 0;
        int i = 1 , j = 0;

        while(i < n) {
            if (colors[i] == colors[j]) {
                time += min(neededTime[i] , neededTime[j]);
                if (neededTime[i] > neededTime[j]) j = i;
            }
            else j = i;
            i++;
        }
        return time;
    }
};
