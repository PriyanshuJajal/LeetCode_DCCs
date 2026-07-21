LEETCODE 3499. Maximize Active Section with Trade I

Let n be the length of s
Time complexity: O(n)
Space complexity: O(1)


class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n = s.size();
        int cnt1 = count(begin(s) , end(s) , '1');

        int i = 0;
        int gain = 0;
        int prev = INT_MIN;
        int curr = 0;

        while(i < n) {
            int st = i;

            while(i < n && s[i] == s[st]) {
                i++;
            }

            if (s[st] == '0') {
                curr = i - st;
                gain = max(gain , curr + prev);
                prev = curr;
            }
        }

        return cnt1 + gain;
    }
};