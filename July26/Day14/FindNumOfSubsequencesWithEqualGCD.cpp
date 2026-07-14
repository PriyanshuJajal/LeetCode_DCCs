// LEETCODE 3336. Find the Number of Subsequences With Equal GCD

// Let n be the length of the array nums, and let m be the maximum element in nums
// Time complexity: O(n * m² * logm)
// Space complexity: O(m²)


class Solution {
public:
    static constexpr int MOD = 1e9 + 7;
    int subsequencePairCount(vector<int>& nums) {
        int m = *max_element(begin(nums) , end(nums));
        int n = nums.size();

        vector<vector<int>> dp(m + 1 , vector<int>(m + 1));
        dp[0][0] = 1;

        for (int num : nums) {
            vector<vector<int>> t(m + 1 , vector<int>(m + 1));

            for (int j = 0; j <= m; j++) {
                int div1 = gcd(j , num);

                for (int k = 0; k <= m; k++) {
                    int val = dp[j][k];
                    if (val == 0) continue;

                    int div2 = gcd(k , num);

                    t[j][k] = (t[j][k] + val) % MOD;
                    t[div1][k] = (t[div1][k] + val) % MOD;
                    t[j][div2] = (t[j][div2] + val) % MOD;
                }
            }
            dp.swap(t);
        }

        int cnt = 0;
        for (int j = 1; j <= m; j++) {
            cnt = (cnt + dp[j][j]) % MOD;
        }
        
        return cnt;
    }
};