// LEETCODE 3161. Block Placement Queries

// There exists an infinite number line, with its origin at 0 and extending towards the positive x-axis.

// You are given a 2D array queries, which contains two types of queries:

// For a query of type 1, queries[i] = [1, x]. Build an obstacle at distance x from the origin. It is guaranteed that there is no obstacle at distance x when the query is asked.
// For a query of type 2, queries[i] = [2, x, sz]. Check if it is possible to place a block of size sz anywhere in the range [0, x] on the line, such that the block entirely lies in the range [0, x]. A block cannot be placed if it intersects with any obstacle, but it may touch it. Note that you do not actually place the block. Queries are separate.
// Return a boolean array results, where results[i] is true if you can place the block specified in the ith query of type 2, and false otherwise.

 

// Example 1:

// Input: queries = [[1,2],[2,3,3],[2,3,1],[2,2,2]]

// Output: [false,true,true]

// Explanation:



// For query 0, place an obstacle at x = 2. A block of size at most 2 can be placed before x = 3.

// Example 2:

// Input: queries = [[1,7],[2,7,6],[1,2],[2,7,5],[2,7,6]]

// Output: [true,true,false]

// Explanation:



// Place an obstacle at x = 7 for query 0. A block of size at most 7 can be placed before x = 7.
// Place an obstacle at x = 2 for query 2. Now, a block of size at most 5 can be placed before x = 7, and a block of size at most 2 before x = 2.
 

// Constraints:

// 1 <= queries.length <= 15 * 104
// 2 <= queries[i].length <= 3
// 1 <= queries[i][0] <= 2
// 1 <= x, sz <= min(5 * 104, 3 * queries.length)
// The input is generated such that for queries of type 1, no obstacle exists at distance x when the query is asked.
// The input is generated such that there is at least one query of type 2.


// Let q be the length of queries, and let M be the maximum value of x.
// Time complexity: O(qlogq + qlogM).
// Space complexity: O(M + q).


class Solution {
public:
    vector<int> bt;

    void update(int x , int v) {
        for (; x < bt.size(); x += x & -x) {
            bt[x] = max(bt[x] , v);
        }
    }

    int query(int x) {
        int res = 0;
        for (; x > 0; x -= x & -x) {
            res = max(res , bt[x]);
        }
        return res;
    }

    vector<bool> getResults(vector<vector<int>>& queries) {
        int mx = 50000;
        set<int> st = {0 , mx};

        for (auto& q : queries) {
            if (q[0] == 1) {
                st.insert(q[1]);
            }
        }

        bt.resize(mx + 1);
        int pre = 0;

        for (int x : st) {
            if (x == 0) {
                continue;
            }
            update(x, x - pre);
            pre = x;
        }

        reverse(begin(queries) , end(queries));
        vector<bool> ans;

        for (auto& q : queries) {
            if (q[0] == 2) {
                int x = q[1];
                int sz = q[2];

                auto it = st.upper_bound(x);
                --it;
                
                int pre = *it;
                int max_space = query(pre);
                max_space = max(max_space , x - pre);

                ans.push_back(max_space >= sz);
            }
            else {
                int x = q[1];
                auto it = st.find(x);

                int pre = *prev(it);
                int nxt = *next(it);
                update(nxt, nxt - pre);

                st.erase(it);
            }
        }
        reverse(begin(ans) , end(ans));
        return ans;
    }
};