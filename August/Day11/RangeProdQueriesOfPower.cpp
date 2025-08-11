// LEETCODE 2438...

// Given a positive integer n, there exists a 0-indexed array called powers, composed of the minimum number of powers of 2 that sum to n. The array is sorted in non-decreasing order, and there is only one way to form the array.

// You are also given a 0-indexed 2D integer array queries, where queries[i] = [lefti, righti]. Each queries[i] represents a query where you have to find the product of all powers[j] with lefti <= j <= righti.

// Return an array answers, equal in length to queries, where answers[i] is the answer to the ith query. Since the answer to the ith query may be too large, each answers[i] should be returned modulo 109 + 7.

 

// Example 1:

// Input: n = 15, queries = [[0,1],[2,2],[0,3]]
// Output: [2,4,64]
// Explanation:
// For n = 15, powers = [1,2,4,8]. It can be shown that powers cannot be a smaller size.
// Answer to 1st query: powers[0] * powers[1] = 1 * 2 = 2.
// Answer to 2nd query: powers[2] = 4.
// Answer to 3rd query: powers[0] * powers[1] * powers[2] * powers[3] = 1 * 2 * 4 * 8 = 64.
// Each answer modulo 109 + 7 yields the same answer, so [2,4,64] is returned.
// Example 2:

// Input: n = 2, queries = [[0,0]]
// Output: [2]
// Explanation:
// For n = 2, powers = [2].
// The answer to the only query is powers[0] = 2. The answer modulo 109 + 7 is the same, so [2] is returned.
 

// Constraints:

// 1 <= n <= 109
// 1 <= queries.length <= 105
// 0 <= starti <= endi < powers.length

// 🚀 Approach
// Extract Powers of 2:
// Iterate through bits of n from 0 to 30. If a bit is set, add 2^i to the powers list.
// Process Queries:
// For each query [start, end], compute the product of powers[start] to powers[end], taking modulo 1e9 + 7 at each step to avoid overflow.
// Return Results:
// Store each query result in an array and return it.



class Solution {
public:
    int m = 1e9 + 7;

    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> powers;
        vector<int> res;

        for (int i = 0; i < 31; i++) {
            if (n & (1 << i)) powers.push_back(1 << i);
        }

        for (auto& query : queries) {
            int st = query[0];
            int end = query[1];
            long long prod = 1;

            for (int i = st; i <= end; i++) {
                prod = (prod * powers[i]) % m;
            }
            res.push_back(prod);
        }
        return res;
    }
};