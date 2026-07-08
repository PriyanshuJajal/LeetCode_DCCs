// LEETCODE 3756. Concatenate Non-Zero Digits and Multiply by Sum II

// n be the length of the input string and m be the number of queries.
// Time complexity: O(n + m)
// Space complexity: O(n)



const int MOD = 1e9 + 7;
const int MAX_N = 100001;
long long pow10[MAX_N];

int init = []() {
    pow10[0] = 1;
    for (int i = 1; i < MAX_N; i++) {
        pow10[i] = (pow10[i - 1] * 10) % MOD;
    }

    return 0;
}();

class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.size();
        vector<int> sum(n + 1 , 0);
        vector<long long> vals(n + 1 , 0);
        vector<int> cnt(n + 1 , 0);

        for (int i = 0; i < n; i++) {
            int d = s[i] - '0';
            sum[i + 1] = sum[i] + d;
            vals[i + 1] = (d > 0) ? (vals[i] * 10 + d) % MOD : vals[i];
            cnt[i + 1] = cnt[i] + (d > 0);
        }

        int m = queries.size();
        vector<int> res(m , 0);

        for (int i = 0; i < m; i++) {
            int l = queries[i][0];
            int r = queries[i][1] + 1;

            int len = cnt[r] - cnt[l];
            long long val = (vals[r] - vals[l] * pow10[len] % MOD + MOD) % MOD;
            long long sumVal = sum[r] - sum[l];

            res[i] = (val * sumVal) % MOD;
        }

        return res;
    }
};