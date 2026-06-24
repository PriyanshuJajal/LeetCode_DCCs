// LEETCODE 3700. Number of ZigZag Arrays II

// You are given three integers n, l, and r.

// A ZigZag array of length n is defined as follows:

// Each element lies in the range [l, r].
// No two adjacent elements are equal.
// No three consecutive elements form a strictly increasing or strictly decreasing sequence.
// Return the total number of valid ZigZag arrays.

// Since the answer may be large, return it modulo 109 + 7.

// A sequence is said to be strictly increasing if each element is strictly greater than its previous one (if exists).

// A sequence is said to be strictly decreasing if each element is strictly smaller than its previous one (if exists).

 

// Example 1:

// Input: n = 3, l = 4, r = 5

// Output: 2

// Explanation:

// There are only 2 valid ZigZag arrays of length n = 3 using values in the range [4, 5]:

// [4, 5, 4]
// [5, 4, 5]
// Example 2:

// Input: n = 3, l = 1, r = 3

// Output: 10

// Explanation:

// ​​​​​​​There are 10 valid ZigZag arrays of length n = 3 using values in the range [1, 3]:

// [1, 2, 1], [1, 3, 1], [1, 3, 2]
// [2, 1, 2], [2, 1, 3], [2, 3, 1], [2, 3, 2]
// [3, 1, 2], [3, 1, 3], [3, 2, 3]
// All arrays meet the ZigZag conditions.

 

// Constraints:

// 3 <= n <= 109
// 1 <= l < r <= 75


// Time complexity: O(m³logn)
// Space complexity: O(m²)



class Solution {
public:
    static constexpr long long MOD = 1e9 + 7;
    typedef long long ll;

    vector<vector<ll>> multiplyMat(const vector<vector<ll>>& a , const vector<vector<ll>>& b) {
        int n = a.size();
        int m = b[0].size();

        vector<vector<ll>> res(n , vector<ll>(m , 0));

        for (int i = 0; i < n; i++) {
            for (int k = 0; k < a[0].size(); k++) {
                long long r = a[i][k];
                if (r == 0) continue;

                for (int j = 0; j < m; j++) {
                    res[i][j] = (res[i][j] + r * b[k][j]) % MOD;
                }
            }
        }

        return res;
    }

    vector<vector<ll>> powMul(vector<vector<ll>> base , ll exp , vector<vector<ll>> res) {
        while(exp > 0) {
            if (exp & 1) {
                res = multiplyMat(res , base);
            }

            base = multiplyMat(base , base);
            exp >>= 1;
        }
        return res;
    }

    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;
        if (n == 1) {
            return m;
        }

        int size = 2 * m;
        vector<vector<ll>> u(size, vector<ll>(size, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < i; j++) {
                u[i][j + m] = 1;
            }
            for (int j = i + 1; j < m; j++) {
                u[i + m][j] = 1;
            }
        }

        vector<vector<ll>> dp(1 , vector<ll>(size , 1));

        dp = powMul(std::move(u) , n - 1 , std::move(dp));

        long long ans = 0;
        for (int i = 0; i < size; i++) {
            ans = (ans + dp[0][i]) % MOD;
        }

        return ans;
    }
};