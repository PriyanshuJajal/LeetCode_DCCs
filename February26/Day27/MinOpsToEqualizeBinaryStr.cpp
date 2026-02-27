// LEETCODE 3666. Minimum Operations to Equalize Binary String

// You are given a binary string s, and an integer k.

// In one operation, you must choose exactly k different indices and flip each '0' to '1' and each '1' to '0'.

// Return the minimum number of operations required to make all characters in the string equal to '1'. If it is not possible, return -1.

 

// Example 1:

// Input: s = "110", k = 1

// Output: 1

// Explanation:

// There is one '0' in s.
// Since k = 1, we can flip it directly in one operation.
// Example 2:

// Input: s = "0101", k = 3

// Output: 2

// Explanation:

// One optimal set of operations choosing k = 3 indices in each operation is:

// Operation 1: Flip indices [0, 1, 3]. s changes from "0101" to "1000".
// Operation 2: Flip indices [1, 2, 3]. s changes from "1000" to "1111".
// Thus, the minimum number of operations is 2.

// Example 3:

// Input: s = "101", k = 2

// Output: -1

// Explanation:

// Since k = 2 and s has only one '0', it is impossible to flip exactly k indices to make all '1'. Hence, the answer is -1.

 

// Constraints:

// 1 <= s.length <= 10​​​​​​​5
// s[i] is either '0' or '1'.
// 1 <= k <= s.length









class Solution {
public:
    int minOperations(string s, int k) {
        int n = s.length();
        int start0s = 0;

        for (char& ch : s) {
            if (ch == '0') start0s++;
        }

        if (start0s == 0) return 0;

        vector<int> ops(n + 1 , -1);

        set<int> evenSet;
        set<int> oddSet;

        for (int i = 0; i <= n; i++) {
            if (i & 1) oddSet.insert(i);
            else evenSet.insert(i);
        }

        queue<int> q;
        q.push(start0s);
        ops[start0s]= 0;

        if (start0s & 1) oddSet.erase(start0s);
        else evenSet.erase(start0s);

        while(!q.empty()) {
            int z = q.front();
            q.pop();

            int minNewZ = z + k - 2 * min(k , z);
            int maxNewZ = z + k - 2 * max(0 , k - n + z);

            set<int>& currSet = (minNewZ & 1) ? oddSet : evenSet;

            auto it = currSet.lower_bound(minNewZ);

            while(it != currSet.end() && *it <= maxNewZ) {
                int newZ = *it;

                if (ops[newZ] == -1) {
                    ops[newZ] = ops[z] + 1;

                    if (newZ == 0) return ops[newZ];
                    q.push(newZ);
                }

                it = currSet.erase(it);
            }
        }
        return -1;
    }
};