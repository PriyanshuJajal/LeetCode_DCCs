// LEETCODE 1291. Sequential Digits

// Time Complexity: O(k log k), where k is the number of sequential digit numbers generated within [low, high]
// Since sequential digit numbers are limited (at most 36 possible), k ≤ 36
// So, algo runs in O(1) time.

// Space Complexity: res stores at most 36 numbers, so O(k) space.
// So O(k), which is bounded by a constant, so O(1).



class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> res;
        for (int i = 1; i <= 9; i++) {
            int num = i;
            for (int j = i + 1; j <= 9; j++) {
                num = num * 10 + j;
                if (num >= low && num <= high) {
                    res.push_back(num);
                }
            }
        }

        sort(begin(res) , end(res));
        return res;
    }
};