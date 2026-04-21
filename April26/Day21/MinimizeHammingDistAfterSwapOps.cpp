// LEETCODE 1722. Minimize Hamming Distance After Swap Operations

// You are given two integer arrays, source and target, both of length n. You are also given an array allowedSwaps where each allowedSwaps[i] = [ai, bi] indicates that you are allowed to swap the elements at index ai and index bi (0-indexed) of array source. Note that you can swap elements at a specific pair of indices multiple times and in any order.

// The Hamming distance of two arrays of the same length, source and target, is the number of positions where the elements are different. Formally, it is the number of indices i for 0 <= i <= n-1 where source[i] != target[i] (0-indexed).

// Return the minimum Hamming distance of source and target after performing any amount of swap operations on array source.

 

// Example 1:

// Input: source = [1,2,3,4], target = [2,1,4,5], allowedSwaps = [[0,1],[2,3]]
// Output: 1
// Explanation: source can be transformed the following way:
// - Swap indices 0 and 1: source = [2,1,3,4]
// - Swap indices 2 and 3: source = [2,1,4,3]
// The Hamming distance of source and target is 1 as they differ in 1 position: index 3.
// Example 2:

// Input: source = [1,2,3,4], target = [1,3,2,4], allowedSwaps = []
// Output: 2
// Explanation: There are no allowed swaps.
// The Hamming distance of source and target is 2 as they differ in 2 positions: index 1 and index 2.
// Example 3:

// Input: source = [5,1,2,4,3], target = [1,5,4,2,3], allowedSwaps = [[0,4],[4,2],[1,3],[1,4]]
// Output: 0
 

// Constraints:

// n == source.length == target.length
// 1 <= n <= 105
// 1 <= source[i], target[i] <= 105
// 0 <= allowedSwaps.length <= 105
// allowedSwaps[i].length == 2
// 0 <= ai, bi <= n - 1
// ai != bi



// 🚀 Approach
// Union-Find Setup
//     Initialize parent and rank arrays.
//     Use unite(a, b) to connect indices from allowedSwaps.
//     After processing, indices that can swap freely belong to the same connected component.
// Build Frequency Maps
//     For each component, build a frequency map of values from source.
//     Store these maps in a dictionary keyed by the component’s representative.
// Match Against Target
//     Iterate through each index in target.
//     If the target value exists in the same component’s frequency map, decrement the count (meaning it’s matched).
//     Otherwise, increment the Hamming distance (unmatched).
// The accumulated unmatched count is the minimum Hamming distance.

// 🕛 Complexity
// Time complexity: O(n + mα(n))
// n = length of source
// m = length of allowedSwaps
// α(n) = inverse Ackermann function

// Space complexity: O(n)


class Solution {
public:
    vector<int> parent;
    vector<int> rank;

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unite(int a , int b) {
        a = find(a);
        b = find(b);

        if (a == b) return;

        if (rank[a] < rank[b]) {
            swap(a , b);
        }
        parent[b] = a;

        if (rank[a] == rank[b]) {
            rank[a]++;
        }
    }

    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = source.size();
        parent.resize(n);
        rank.resize(n , 0);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }

        for (auto& pair : allowedSwaps) {
            unite(pair[0] , pair[1]);
        }

        unordered_map<int , unordered_map<int , int>> sets;
        for (int i = 0; i < n; i++) {
            int f = find(i);
            sets[f][source[i]]++;
        }

        int minHammingDist = 0;
        for (int i = 0; i < n; i++) {
            int f = find(i);
            if (sets[f][target[i]] > 0) {
                sets[f][target[i]]--;
            }
            else minHammingDist++;
        }
        return minHammingDist;
    }
};