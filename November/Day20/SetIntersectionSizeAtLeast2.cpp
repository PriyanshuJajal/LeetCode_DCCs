// LEETCODE 757. Set Intersection Size At Least Two

// You are given a 2D integer array intervals where intervals[i] = [starti, endi] represents all the integers from starti to endi inclusively.

// A containing set is an array nums where each interval from intervals has at least two integers in nums.

// For example, if intervals = [[1,3], [3,7], [8,9]], then [1,2,4,7,8,9] and [2,3,4,8,9] are containing sets.
// Return the minimum possible size of a containing set.

 

// Example 1:

// Input: intervals = [[1,3],[3,7],[8,9]]
// Output: 5
// Explanation: let nums = [2, 3, 4, 8, 9].
// It can be shown that there cannot be any containing array of size 4.
// Example 2:

// Input: intervals = [[1,3],[1,4],[2,5],[3,5]]
// Output: 3
// Explanation: let nums = [2, 3, 4].
// It can be shown that there cannot be any containing array of size 2.
// Example 3:

// Input: intervals = [[1,2],[2,3],[2,4],[4,5]]
// Output: 5
// Explanation: let nums = [1, 2, 3, 4, 5].
// It can be shown that there cannot be any containing array of size 4.
 

// Constraints:

// 1 <= intervals.length <= 3000
// intervals[i].length == 2
// 0 <= starti < endi <= 108



// 🚀 Approach
// Sort intervals:
//     By increasing end value.
//     If ends are equal, by decreasing start value.
//     This ensures we handle tighter intervals first and maximize reuse of previously added elements.
// Track selected elements:
//     Use an array nums to store selected elements.
//     For each interval, count how many elements in nums fall within the interval.
//     If fewer than 2, add the largest possible elements (end , end - 1) to cover the interval.
// Greedy insertion:
//     If no elements cover the interval, insert end - 1 & end.
//     If one element covers it, insert the one that ensures coverage and maintains order.


// 🕛 Complexity
// Time complexity: O(n²)
// Sorting: O(nlog n)
// Processing intervals: O(n^2) in worst case due to scanning nums

// Space complexity: O(n)












class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        sort(begin(intervals) , end(intervals) , [](vector<int>& a , vector<int>& b) {
            if (a[1] != b[1]) return a[1] < b[1];
            return a[0] > b[0];
        });

        vector<int> nums;
        for (auto& interval : intervals) {
            int st = interval[0];
            int end = interval[1];

            int cnt = 0;
            for (int i = nums.size() - 1; i >= 0; i--) {
                if (nums[i] < st) break;
                cnt++;
            }

            if (cnt == 0) {
                nums.push_back(end - 1);
                nums.push_back(end);
            }
            else if (cnt == 1) {
                if (nums.back() == end) nums.push_back(end - 1);
                else nums.push_back(end);

                sort(nums.end() - 2 , nums.end());
            }
        }
        return nums.size();
    }
};