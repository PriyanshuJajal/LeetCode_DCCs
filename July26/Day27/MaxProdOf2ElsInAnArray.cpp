// LEETCODE 1464. Maximum Product of Two Elements in an Array

// Time complexity: O(n)
// Space complexity: O(1)

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int first = 0 , second = 0;
        for (int num : nums) {
            if (num > first) {
                second = first;
                first = num;
            }
            else if (num > second) {
                second = num;
            }
        }

        return (first - 1) * (second - 1);
    }
};