// LEETCODE 11. Container With Most Water

// You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).

// Find two lines that together with the x-axis form a container, such that the container contains the most water.

// Return the maximum amount of water a container can store.

// Notice that you may not slant the container.

 

// Example 1:


// Input: height = [1,8,6,2,5,4,8,3,7]
// Output: 49
// Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.
// Example 2:

// Input: height = [1,1]
// Output: 1
 

// Constraints:

// n == height.length
// 2 <= n <= 105
// 0 <= height[i] <= 104



// 🚀 Approach
// Use two pointers, one at the start and one at the end of the array. At each step:
//     Calculate the area formed by the lines at the two pointers.
//     Move the pointer pointing to the shorter line inward, hoping to find a taller line that might increase the area.
//     Keep track of the maximum area found during the process.
// This greedy approach ensures we explore all relevant combinations without checking every pair.





class Solution {
    public int maxArea(int[] height) {
        int n = height.length;
        int i = 0;
        int j = n - 1;
        int maxWater = 0;

        while(i <= j) {
            int water = 0;
            if (height[i] <= height[j]) {
                water += height[i] * (j - i);
                i++;
            }
            else if (height[i] > height[j]) {
                water += height[j] * (j - i);
                j--;
            }
            maxWater = Math.max(maxWater , water);
        }
        return maxWater;
    }
}