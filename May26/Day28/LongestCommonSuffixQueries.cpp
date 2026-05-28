// LEETCODE 3093. Longest Common Suffix Queries

// You are given two arrays of strings wordsContainer and wordsQuery.

// For each wordsQuery[i], you need to find a string from wordsContainer that has the longest common suffix with wordsQuery[i]. If there are two or more strings in wordsContainer that share the longest common suffix, find the string that is the smallest in length. If there are two or more such strings that have the same smallest length, find the one that occurred earlier in wordsContainer.

// Return an array of integers ans, where ans[i] is the index of the string in wordsContainer that has the longest common suffix with wordsQuery[i].

 

// Example 1:

// Input: wordsContainer = ["abcd","bcd","xbcd"], wordsQuery = ["cd","bcd","xyz"]

// Output: [1,1,1]

// Explanation:

// Let's look at each wordsQuery[i] separately:

// For wordsQuery[0] = "cd", strings from wordsContainer that share the longest common suffix "cd" are at indices 0, 1, and 2. Among these, the answer is the string at index 1 because it has the shortest length of 3.
// For wordsQuery[1] = "bcd", strings from wordsContainer that share the longest common suffix "bcd" are at indices 0, 1, and 2. Among these, the answer is the string at index 1 because it has the shortest length of 3.
// For wordsQuery[2] = "xyz", there is no string from wordsContainer that shares a common suffix. Hence the longest common suffix is "", that is shared with strings at index 0, 1, and 2. Among these, the answer is the string at index 1 because it has the shortest length of 3.
// Example 2:

// Input: wordsContainer = ["abcdefgh","poiuygh","ghghgh"], wordsQuery = ["gh","acbfgh","acbfegh"]

// Output: [2,0,2]

// Explanation:

// Let's look at each wordsQuery[i] separately:

// For wordsQuery[0] = "gh", strings from wordsContainer that share the longest common suffix "gh" are at indices 0, 1, and 2. Among these, the answer is the string at index 2 because it has the shortest length of 6.
// For wordsQuery[1] = "acbfgh", only the string at index 0 shares the longest common suffix "fgh". Hence it is the answer, even though the string at index 2 is shorter.
// For wordsQuery[2] = "acbfegh", strings from wordsContainer that share the longest common suffix "gh" are at indices 0, 1, and 2. Among these, the answer is the string at index 2 because it has the shortest length of 6.
 

// Constraints:

// 1 <= wordsContainer.length, wordsQuery.length <= 104
// 1 <= wordsContainer[i].length <= 5 * 103
// 1 <= wordsQuery[i].length <= 5 * 103
// wordsContainer[i] consists only of lowercase English letters.
// wordsQuery[i] consists only of lowercase English letters.
// Sum of wordsContainer[i].length is at most 5 * 105.
// Sum of wordsQuery[i].length is at most 5 * 105.


// Time Complexity: O(m + n) , where m is the total number of characters in wordsContainer and n is the average length of words in wordsQuery
// Space Complexity: O(26 * m) 



class Solution {
public:
    struct TrieNode {
        int idx;
        TrieNode* child[26];

        ~TrieNode() {
            for (int i = 0; i < 26; i++) {
                delete child[i];
            }
        }
    };

    TrieNode* getNode(int i) {
        TrieNode* t = new TrieNode();
        t -> idx = i;

        for (int i = 0; i < 26; i++) {
            t -> child[i] = nullptr;
        }
        return t;
    }

    void insert(TrieNode* root , int i , vector<string>& wordsContainer) {
        string word = wordsContainer[i];
        int n = word.length();

        for (int j = n - 1; j >= 0; j--) {
            int chIdx = word[j] - 'a';

            if (root -> child[chIdx] == nullptr) {
                root -> child[chIdx] = getNode(i);
            }

            root = root -> child[chIdx];

            if (wordsContainer[root -> idx].length() > n) {
                root -> idx = i;
            }
        }
    }

    int search(TrieNode* root , string& word) {
        int resIdx = root -> idx;
        int n = word.length();

        for (int i = n - 1; i >= 0; i--) {
            int chIdx = word[i] - 'a';

            root = root -> child[chIdx];
            if (root == nullptr) {
                return resIdx;
            }

            resIdx = root -> idx;
        }
        return resIdx;
    }

    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        int m = wordsContainer.size();
        int n = wordsQuery.size();

        vector<int> res(n);
        TrieNode* root = getNode(0);

        for (int i = 0; i < m; i++) {
            int idx = root -> idx;
            if (wordsContainer[idx].length() > wordsContainer[i].length()) {
                root -> idx = i;
            }

            insert(root , i , wordsContainer);
        }
        
        for (int i = 0; i < n; i++) {
            res[i] = search(root , wordsQuery[i]);
        }

        delete root;

        return res;
    }
};