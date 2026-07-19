// LEETCODE 1081. Smallest Subsequence of Distinct Characters

// Time complexity: O(N)
// Space complexity: O(26) ~ O(1)



class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> vis(26);
        vector<int> num(26);

        for (char ch : s) {
            num[ch - 'a']++;
        }

        string st;
        for (char ch : s) {
            if (!vis[ch - 'a']) {
                while(!st.empty() && st.back() > ch) {
                    if (num[st.back() - 'a'] > 0) {
                        vis[st.back() - 'a'] = 0;
                        st.pop_back();
                    }
                    else break;
                }

                vis[ch - 'a'] = 1;
                st.push_back(ch);
            }
            num[ch - 'a'] -= 1;
        }
        return st;
    }
};