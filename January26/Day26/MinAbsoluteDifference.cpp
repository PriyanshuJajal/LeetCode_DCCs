// LEETCODE 1200. Minimum Absolute Difference

// Given an array of distinct integers arr, find all pairs of elements with the minimum absolute difference of any two elements.

// Return a list of pairs in ascending order(with respect to pairs), each pair [a, b] follows

// a, b are from arr
// a < b
// b - a equals to the minimum absolute difference of any two elements in arr
 

// Example 1:

// Input: arr = [4,2,1,3]
// Output: [[1,2],[2,3],[3,4]]
// Explanation: The minimum absolute difference is 1. List all pairs with difference equal to 1 in ascending order.
// Example 2:

// Input: arr = [1,3,6,10,15]
// Output: [[1,3]]
// Example 3:

// Input: arr = [3,8,-10,23,19,-4,-14,27]
// Output: [[-14,-10],[19,23],[23,27]]
 

// Constraints:

// 2 <= arr.length <= 105
// -106 <= arr[i] <= 106


// 🚀 Approach
// Sort the array: Sorting arr ensures that the smallest differences will appear between consecutive elements.
// Initialize variables:
//     minDiff to track the smallest difference found so far.
//     res to store all pairs that match this minimum difference.
// Iterate through consecutive pairs:
//     Compute the difference between arr[i + 1] & arr[i].
//     If this difference is smaller than minDiff, update minDiff, clear the result vector, and add the new pair.
//     If the difference equals minDiff, simply add the pair to the result vector.
// Return res as the final answer.

// 🕛 Complexity
// Time complexity: O(nlogn)
// Space complexity: O(n)









class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(begin(arr) , end(arr));
        int n = arr.size();
        vector<vector<int>> res;
        int minDiff = INT_MAX;

        for (int i = 0; i < n - 1; i++) {
            int diff = arr[i + 1] - arr[i];
            if (diff < minDiff) {
                minDiff = diff;
                res.clear();
                res.push_back({arr[i] , arr[i + 1]});
            }
            else if (diff == minDiff) {
                res.push_back({arr[i] , arr[i + 1]});
            }
        }
        return res;
    }
};