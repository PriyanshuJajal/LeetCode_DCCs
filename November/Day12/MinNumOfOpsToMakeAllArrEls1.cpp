// LEETCODE 2654. Minimum Number of Operations to Make All Array Elements Equal to 1


// You are given a 0-indexed array nums consisiting of positive integers. You can do the following operation on the array any number of times:

// Select an index i such that 0 <= i < n - 1 and replace either of nums[i] or nums[i+1] with their gcd value.
// Return the minimum number of operations to make all elements of nums equal to 1. If it is impossible, return -1.

// The gcd of two integers is the greatest common divisor of the two integers.

 

// Example 1:

// Input: nums = [2,6,3,4]
// Output: 4
// Explanation: We can do the following operations:
// - Choose index i = 2 and replace nums[2] with gcd(3,4) = 1. Now we have nums = [2,6,1,4].
// - Choose index i = 1 and replace nums[1] with gcd(6,1) = 1. Now we have nums = [2,1,1,4].
// - Choose index i = 0 and replace nums[0] with gcd(2,1) = 1. Now we have nums = [1,1,1,4].
// - Choose index i = 2 and replace nums[3] with gcd(1,4) = 1. Now we have nums = [1,1,1,1].
// Example 2:

// Input: nums = [2,10,6,14]
// Output: -1
// Explanation: It can be shown that it is impossible to make all the elements equal to 1.
 

// Constraints:

// 2 <= nums.length <= 50
// 1 <= nums[i] <= 106




// 🚀 Approach
// Count how many elements are already 1. If any exist, the minimum operations are n - ones.
// If no 1 exists, iterate over all subarrays and compute their GCD.
// If a subarray has GCD 1, record its length.
//     The minimum operations needed are:
//         (length of subarray - 1) to reduce it to a single 1
//         (n - 1) to convert all other elements to 1 using the new one


// If no subarray has GCD 1, return -1.
// 🕛 Complexity
// Time complexity: O(n² * logM)
// M is the max element in the array (worst-case for gcd)
// Space complexity: O(1)










class Solution {
public:
    int gcd(int a , int b) {
        while(b) {
            a %= b;
            swap(a , b);
        }
        return a;
    }

    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int ones = 0;
        for (int x : nums) {
            if (x == 1) ones++;
        }

        if (ones > 0) return n - ones;
        int minLen = INT_MAX;

        for (int i = 0; i < n; i++) {
            int g = nums[i];
            for (int j = i; j < n; j++) {
                g = gcd(g , nums[j]);
                if (g == 1) {
                    int len = j - i + 1;
                    minLen = min(minLen , len);
                    break;
                }
            }
        }

        if (minLen == INT_MAX) return -1;
        else return (minLen - 1) + (n - 1);
    }
};