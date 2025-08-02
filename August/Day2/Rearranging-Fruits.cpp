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
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        int n = basket1.size();
        // Copy for the two basket arrays...
        auto& b1 = basket1;
        auto& b2 = basket2;

        // Sort the arrays in ascending order...
        sort(begin(b1) , end(b1));
        sort(begin(b2) , end(b2));

        // Store the min value of both arrays...
        int mini = min(b1[0] , b2[0]);

        // Doubles the smallest fruit value across both baskets to prep for 
        // the fallback swap cost...
        mini <<= 1;

        int i , j , k , l;
        i = j = k = l = 0;
        
        // Two-Pointers Approach...
        while(i < n && j < n) {
            if (b1[i] == b2[j]) {
                i++;
                j++;
            }

            else if (b1[i] < b2[j]) {
                // Check if there is duplicate, so that it can be swapped...
                if (i == n - 1 || b1[i] != b1[i + 1]) return -1;
                b1[k++] = b1[i];
                i += 2;
            }
            else {
                // Check if there is duplicate, so that it can be swapped...
                if (j == n - 1 || b2[j] != b2[j + 1]) return -1;
                b2[l++] = b2[j];
                j += 2;
            }
        }

        // If there are any elements remaining...
        while(i < n) {
            if (b1[i] != b1[i + 1]) return -1;
            b1[k++] = b1[i];
            i += 2;
        }
        while(j < n) {
            if (b2[j] != b2[j + 1]) return -1;
            b2[l++] = b2[j];
            j += 2;
        }

        // Final output...
        long long cost = 0;
        for (int i = 0; i < k; i++) {
            // Take min from both arrays & mini(global) value...
            cost += min(min(b1[i] , b2[k - 1 - i]) , mini);
        }
        return cost;
    }
};