// LEETCODE 3488. Closest Equal Element Queries

// You are given a circular array nums and an array queries.

// For each query i, you have to find the following:

// The minimum distance between the element at index queries[i] and any other index j in the circular array, where nums[j] == nums[queries[i]]. If no such index exists, the answer for that query should be -1.
// Return an array answer of the same size as queries, where answer[i] represents the result for query i.

 

// Example 1:

// Input: nums = [1,3,1,4,1,3,2], queries = [0,3,5]

// Output: [2,-1,3]

// Explanation:

// Query 0: The element at queries[0] = 0 is nums[0] = 1. The nearest index with the same value is 2, and the distance between them is 2.
// Query 1: The element at queries[1] = 3 is nums[3] = 4. No other index contains 4, so the result is -1.
// Query 2: The element at queries[2] = 5 is nums[5] = 3. The nearest index with the same value is 1, and the distance between them is 3 (following the circular path: 5 -> 6 -> 0 -> 1).
// Example 2:

// Input: nums = [1,2,3,4], queries = [0,1,2,3]

// Output: [-1,-1,-1,-1]

// Explanation:

// Each value in nums is unique, so no index shares the same value as the queried element. This results in -1 for all queries.

 

// Constraints:

// 1 <= queries.length <= nums.length <= 105
// 1 <= nums[i] <= 106
// 0 <= queries[i] < nums.length



// 🚀 Approach
// Preprocessing:
//     Store all indices of each value in a hashmap (unordered_map<int, vector<int>>).
//     Each vector of indices is sorted naturally as we traverse nums.
// Answering Queries:
//     For each query index q, get the value nums[q].
//     Retrieve the list of indices where this value occurs.
//     If the list size is 1, return -1 (no other occurrence).
//     Otherwise, use lower_bound to find the position of q in the list.
//     Check the right neighbor and left neighbor in the list, computing both direct and circular distances.
//     Take the minimum of these distances.
// Circular Distance Calculation:
//     For two indices a and b, the circular distance is:
//         min(|a - b| , n - |a - b|)
// Store the minimum distance for each query in the result vector.

// 🕛 Complexity
// Time complexity: O(n + qlogn)
//     Preprocessing: O(n)
//     Each query takes O(logn) time for binary search & checks
    
// Space complexity: O(n + q)



class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        unordered_map<int , vector<int>> mp;

        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }

        vector<int> res;
        for (int q : queries) {
            int val = nums[q];
            vector<int>& v = mp[val];

            int s = v.size();
            if (s == 1) {
                res.push_back(-1);
                continue;
            }

            int pos = lower_bound(begin(v) , end(v) , q) - begin(v);
            int minDist = INT_MAX;

            // For Right Neighbor...
            int r = v[(pos + 1) % s];
            int d = abs(q - r);
            int cd = n - d;
            minDist = min({minDist , d , cd});
            
            // For Left Neighbor...
            int l = v[(pos - 1 + s) % s];
            d = abs(q - l);
            cd = n - d;
            minDist = min({minDist , d , cd});

            res.push_back(minDist);
        }
        return res;
    }
};