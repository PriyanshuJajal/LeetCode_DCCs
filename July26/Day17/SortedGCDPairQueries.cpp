// LEETCODE 3312. Sorted GCD Pair Queries

// Let m be the maximum value in nums and let q be the length of queries.

// Time complexity: O(mlogm + qlogm)
// Space complexity: O(m)



class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int m = *max_element(begin(nums) , end(nums));
        vector<long long> cnt(m + 1);

        for (int num : nums) {
            cnt[num]++;
        }

        for (int i = 1; i <= m; i++) {
            for (int j = i * 2; j <= m; j += i) {
                cnt[i] += cnt[j];
            }
        }

        for (int i = 1; i <= m; i++) {
            cnt[i] = cnt[i] * (cnt[i] - 1) / 2;
        }

        for (int i = m; i >= 1; i--) {
            for (int j = i * 2; j <= m; j += i) {
                cnt[i] -= cnt[j];
            }
        }

        for (int i = 1; i <= m; i++) {
            cnt[i] += cnt[i - 1];
        }

        vector<int> res;
        for (long long q : queries) {
            q++;
            int pos = lower_bound(begin(cnt) , end(cnt) , q) - cnt.begin();
            res.push_back(pos);
        }

        return res;
    }
};