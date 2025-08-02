// LEETCODE - 2561...

// You have two fruit baskets containing n fruits each. You are given two 0-indexed integer arrays basket1 and basket2 representing the cost of fruit in each basket. You want to make both baskets equal. To do so, you can use the following operation as many times as you want:

// Chose two indices i and j, and swap the ith fruit of basket1 with the jth fruit of basket2.
// The cost of the swap is min(basket1[i],basket2[j]).
// Two baskets are considered equal if sorting them according to the fruit cost makes them exactly the same baskets.

// Return the minimum cost to make both the baskets equal or -1 if impossible.

 

// Example 1:

// Input: basket1 = [4,2,2,2], basket2 = [1,4,1,2]
// Output: 1
// Explanation: Swap index 1 of basket1 with index 0 of basket2, which has cost 1. Now basket1 = [4,1,2,2] and basket2 = [2,4,1,2]. Rearranging both the arrays makes them equal.
// Example 2:

// Input: basket1 = [2,3,4,1], basket2 = [3,2,5,1]
// Output: -1
// Explanation: It can be shown that it is impossible to make both the baskets equal.
 

// Constraints:

// basket1.length == basket2.length
// 1 <= basket1.length <= 105
// 1 <= basket1[i],basket2[i] <= 109

class Solution {
    public long minCost(int[] basket1, int[] basket2) {
        int n = basket1.length;

        // Sort the arrays in ascending order...
        Arrays.sort(basket1);
        Arrays.sort(basket2);

        // Store the min value of both arrays...
        int mini = Math.min(basket1[0] , basket2[0]);

        // Doubles the smallest fruit value across both baskets to prep for 
        // the fallback swap cost...
        mini <<= 1;

        int i = 0 , j = 0 , l = 0, k = 0;
        // Copy for the two basket arrays...
        int[] b1 = new int[n];
        int[] b2 = new int[n];

        // Two-Pointers Approach...
        while(i < n && j < n) {
            if (basket1[i] == basket2[j]) {
                i++;
                j++;
            }
            else if (basket1[i] < basket2[j]) {
                // Check if there is duplicate, so that it can be swapped...
                if (i == n - 1 || basket1[i] != basket1[i + 1]) return -1;
                b1[k++] = basket1[i];
                i += 2;
            }
            else {
                // Check if there is duplicate, so that it can be swapped...
                if (j == n - 1 || basket2[j] != basket2[j + 1]) return -1;
                b2[l++] = basket2[j];
                j += 2;
            }
        }

        // If there are any elements remaining...
        while(i < n) {
            if (basket1[i] != basket1[i + 1]) return -1;
            b1[k++] = basket1[i];
            i += 2;
        } 

        while(j < n) {
            if (basket2[j] != basket2[j + 1]) return -1;
            b2[l++] = basket2[j];
            j += 2;
        } 

        // Final output...
        long cost = 0;
        for (int x = 0; x < k; x++) {
            // Take min from both arrays & mini(global) value...
            cost += Math.min(Math.min(b1[x] , b2[k - x - 1]) , mini);
        }
        return cost;
    }
}