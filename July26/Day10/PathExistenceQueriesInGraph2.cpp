// LEETCODE 3534. Path Existence Queries in a Graph II

// n = length of nums
// q = length of queries
// Time complexity: O((n + q) * logn)
// Space complexity: O(nlogn)



class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<pair<int , int>> arr(n);
        for (int i = 0; i < n; i++) {
            arr[i] = {nums[i] , i};
        }

        sort(begin(arr) , end(arr));

        vector<int> getI(n);
        for (int i = 0; i < n; i++) {
            getI[arr[i].second] = i;
        }

        vector<vector<int>> st(n , vector<int>(18));
        int r = 0;

        for (int i = 0; i < n; i++) {
            if (r < i) r = i;
            while(r + 1 < n && arr[r + 1].first - arr[r].first <= maxDiff &&
                    arr[r + 1].first - arr[i].first <= maxDiff) {
                r++;
            } 

            st[i][0] = r;
        }

        for (int j = 1; j < 18; j++) {
            for (int i = 0; i < n; i++) {
                st[i][j] = st[st[i][j - 1]][j - 1];
            }
        }

        int q = queries.size();
        vector<int> ans(q , - 1);
        for (int i = 0; i < q; i++) {
            int a = getI[queries[i][0]];
            int b = getI[queries[i][1]];

            if (a > b) swap(a , b);

            if (a == b) {
                ans[i] = 0;
                continue;
            }

            int curr = a;
            int steps = 0;

            for (int j = 17; j >= 0; j--) {
                if (st[curr][j] < b) {
                    curr = st[curr][j];
                    steps += (1 << j);
                }
            }

            ans[i] = (st[curr][0] >= b) ? steps + 1 : -1;
        }

        return ans;
    }
};