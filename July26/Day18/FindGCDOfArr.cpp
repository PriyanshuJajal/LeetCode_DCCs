// LEETCODE 1979. Find Greatest Common Divisor of Array

// Time Complexity: O(n) , n = length of nums
// Space Complexity: O(1)



class Solution {
public:
    int findGCD(vector<int>& nums) {
        int minEl = INT_MAX;
        int maxEl = INT_MIN;
        for (int num : nums) {
            minEl = min(minEl , num);
            maxEl = max(maxEl , num);
        }

        return gcd(minEl , maxEl);
    }
};