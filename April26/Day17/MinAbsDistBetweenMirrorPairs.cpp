// LEETCODE 3761. Minimum Absolute Distance Between Mirror Pairs

// You are given an integer array nums.

// A mirror pair is a pair of indices (i, j) such that:

// 0 <= i < j < nums.length, and
// reverse(nums[i]) == nums[j], where reverse(x) denotes the integer formed by reversing the digits of x. Leading zeros are omitted after reversing, for example reverse(120) = 21.
// Return the minimum absolute distance between the indices of any mirror pair. The absolute distance between indices i and j is abs(i - j).

// If no mirror pair exists, return -1.

 

// Example 1:

// Input: nums = [12,21,45,33,54]

// Output: 1

// Explanation:

// The mirror pairs are:

// (0, 1) since reverse(nums[0]) = reverse(12) = 21 = nums[1], giving an absolute distance abs(0 - 1) = 1.
// (2, 4) since reverse(nums[2]) = reverse(45) = 54 = nums[4], giving an absolute distance abs(2 - 4) = 2.
// The minimum absolute distance among all pairs is 1.

// Example 2:

// Input: nums = [120,21]

// Output: 1

// Explanation:

// There is only one mirror pair (0, 1) since reverse(nums[0]) = reverse(120) = 21 = nums[1].

// The minimum absolute distance is 1.

// Example 3:

// Input: nums = [21,120]

// Output: -1

// Explanation:

// There are no mirror pairs in the array.

 

// Constraints:

// 1 <= nums.length <= 105
// 1 <= nums[i] <= 109​​​​


// 🚀 Approach
// Traverse the array from right to left.
// For each number:
//     Compute its reverse.
//     Check if the reverse exists in the hash map. If yes, update the minimum distance using the stored index.
//     Store the current number with its index in the hash map (ensuring we always keep the closest index for future comparisons).
// After traversal, return the minimum distance if found, otherwise return -1.

// 🕛 Complexity
// Time complexity: O(n * d) , d = number of digits in each number
// Space complexity: O(n)


class Solution {
public:
    int reverse(int num) {
        int rev = 0;
        while(num != 0) {
            int r = num % 10;
            rev = rev * 10 + r;
            num /= 10;
        }
        return rev;
    }

    int minMirrorPairDistance(vector<int>& nums) {
        int n = nums.size();
        int minDist = INT_MAX;
        unordered_map<int , int> mp;
        
        for (int i = n - 1; i >= 0; i--) {
            int revNum = reverse(nums[i]);
            if (mp.count(revNum)) {
                minDist = min(minDist , abs(i - mp[revNum]));
            }
            
            mp[nums[i]] = i;
        }
        
        return minDist == INT_MAX ? -1 : minDist;
    }
};