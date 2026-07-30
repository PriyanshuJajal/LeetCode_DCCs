// LEETCODE 3014. Minimum Number of Pushes to Type Word I

// Time complexity: O(n)
// Space complexity: O(1)

class Solution {
public:
    int minimumPushes(string word) {
        int n = word.length();
        int minPush = 0;

        for (int i = 0; i < n; i++) {
            minPush += i / 8 + 1;
        }
        
        return minPush;
    }
};