// LEETCODE 3016. Minimum Number of Pushes to Type Word II

// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int minimumPushes(string word) {
        vector<int> freq(26 , 0);
        for (char ch : word) {
            freq[ch - 'a']++;
        }

        sort(rbegin(freq) , rend(freq));

        int minPush = 0;
        for (int i = 0; i < 26; i++) {
            if (freq[i] == 0) break;

            minPush += (i / 8 + 1) * freq[i];
        }

        return minPush;
    }
};