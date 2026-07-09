// LEETCODE 3532. Path Existence Queries in a Graph I


// n = length of nums
// q = length of queries

// Time complexity: O(n + q)
// Space complexity: O(n)



class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int> component(n , 0);
        int comp = 0;

        for (int i = 1; i < n; i++) {
            if (nums[i] - nums[i - 1] > maxDiff) {
                comp++;
            }

            component[i] = comp;
        }

        vector<bool> ans;
        for (auto& q : queries) {
            ans.push_back(component[q[0]] == component[q[1]]);
        }

        return ans;
    }
};