// LEETCODE 3228. Maximum Number of Operations to Move Ones to the End

// You are given a binary string s.

// You can perform the following operation on the string any number of times:

// Choose any index i from the string where i + 1 < s.length such that s[i] == '1' and s[i + 1] == '0'.
// Move the character s[i] to the right until it reaches the end of the string or another '1'. For example, for s = "010010", if we choose i = 1, the resulting string will be s = "000110".
// Return the maximum number of operations that you can perform.

 

// Example 1:

// Input: s = "1001101"

// Output: 4

// Explanation:

// We can perform the following operations:

// Choose index i = 0. The resulting string is s = "0011101".
// Choose index i = 4. The resulting string is s = "0011011".
// Choose index i = 3. The resulting string is s = "0010111".
// Choose index i = 2. The resulting string is s = "0001111".
// Example 2:

// Input: s = "00111"

// Output: 0

 

// Constraints:

// 1 <= s.length <= 105
// s[i] is either '0' or '1'.




// 🚀 Approach
// Traverse the string character by character.
// Count the number of 1s encountered so far (cnt1s).
// When a 0 is found after at least one 1, mark found0 = true.
// When a 1 is found and found0 is true, perform cnt1s operations and reset found0.
// After the loop, if a trailing 0 was found, add cnt1s to ops.


// 🕛 Complexity
// Time complexity: O(n)
// Space complexity: O(1)











class Solution {
public:
    int maxOperations(string s) {
        int ops = 0;
        int cnt1s = 0;
        bool found0 = false;

        for (char ch : s) {
            if (ch == '1') {
                if (found0) {
                    ops += cnt1s;
                    found0 = false;
                }
                cnt1s++;
            }
            else {
                if (cnt1s > 0) found0 = true;
            }
        }

        if (found0) ops += cnt1s;
        return ops;
    }
};