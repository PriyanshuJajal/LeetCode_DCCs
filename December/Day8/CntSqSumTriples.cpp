// LEETCODE 1925. Count Square Sum Triples


// A square triple (a,b,c) is a triple where a, b, and c are integers and a2 + b2 = c2.

// Given an integer n, return the number of square triples such that 1 <= a, b, c <= n.

 

// Example 1:

// Input: n = 5
// Output: 2
// Explanation: The square triples are (3,4,5) and (4,3,5).
// Example 2:

// Input: n = 10
// Output: 4
// Explanation: The square triples are (3,4,5), (4,3,5), (6,8,10), and (8,6,10).
 

// Constraints:

// 1 <= n <= 250



// 🚀 Approach
// Iterate over all possible values of a and b from 1 to n.
// For each pair, compute sqSum = a² + b².
// Take the integer square root of sqSum and check if it is a valid integer c such that c² = sqSum.
// Ensure that c <= n.
// If the condition holds, increment the count.
// Return the final count after checking all pairs.
// This approach leverages the fact that we only need to check up to n, and the square root check ensures correctness without iterating over all possible c.


// 🕛 Complexity
// Time complexity: O(n²)
// Space complexity: O(1)











class Solution {
public:
    int countTriples(int n) {
        int cnt = 0;
        for (int a = 1; a <= n; a++) {
            for (int b = 1; b <= n; b++) {
                int sqSum = a * a + b * b;
                int c = sqrt(sqSum);
                if (c <= n && c * c == sqSum) cnt++;
            }
        }
        return cnt;
    }
};