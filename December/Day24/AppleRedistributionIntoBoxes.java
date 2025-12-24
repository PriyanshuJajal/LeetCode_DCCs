// LEETCODE 3074. Apple Redistribution into Boxes

// You are given an array apple of size n and an array capacity of size m.

// There are n packs where the ith pack contains apple[i] apples. There are m boxes as well, and the ith box has a capacity of capacity[i] apples.

// Return the minimum number of boxes you need to select to redistribute these n packs of apples into boxes.

// Note that, apples from the same pack can be distributed into different boxes.

 

// Example 1:

// Input: apple = [1,3,2], capacity = [4,3,1,5,2]
// Output: 2
// Explanation: We will use boxes with capacities 4 and 5.
// It is possible to distribute the apples as the total capacity is greater than or equal to the total number of apples.
// Example 2:

// Input: apple = [5,5,5], capacity = [2,4,2,7]
// Output: 4
// Explanation: We will need to use all the boxes.
 

// Constraints:

// 1 <= n == apple.length <= 50
// 1 <= m == capacity.length <= 50
// 1 <= apple[i], capacity[i] <= 50
// The input is generated such that it's possible to redistribute packs of apples into boxes.





// 🚀 Approach
// Compute the total number of apples by summing the apple array.
// Sort the capacity array in descending order so that we can pick the largest boxes first.
// Iterate through the sorted capacities, subtracting each box's capacity from the total apples still needed.
// Count how many boxes are used until the remaining apples become zero or negative.
// Return the count as the minimum number of boxes required.

// 🕛 Complexity
// Time complexity: O(n + mlogm)
// n = length of apples
// m = length of capacity

// Space complexity: O(1)









public int minimumBoxes(int[] apple, int[] capacity) {
        int total = 0;
        for (int a : apple) {
            total += a;
        }

        Arrays.sort(capacity);
        int cnt = 0;
        for (int i = capacity.length - 1; i >= 0; i--) {
            total -= capacity[i];
            cnt++;
            if (total <= 0) {
                return cnt;
            }
        }

        return 0; 
    }
