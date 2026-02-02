// LEETCODE 3013. Divide an Array Into Subarrays With Minimum Cost II

// You are given a 0-indexed array of integers nums of length n, and two positive integers k and dist.

// The cost of an array is the value of its first element. For example, the cost of [1,2,3] is 1 while the cost of [3,4,1] is 3.

// You need to divide nums into k disjoint contiguous subarrays, such that the difference between the starting index of the second subarray and the starting index of the kth subarray should be less than or equal to dist. In other words, if you divide nums into the subarrays nums[0..(i1 - 1)], nums[i1..(i2 - 1)], ..., nums[ik-1..(n - 1)], then ik-1 - i1 <= dist.

// Return the minimum possible sum of the cost of these subarrays.

 

// Example 1:

// Input: nums = [1,3,2,6,4,2], k = 3, dist = 3
// Output: 5
// Explanation: The best possible way to divide nums into 3 subarrays is: [1,3], [2,6,4], and [2]. This choice is valid because ik-1 - i1 is 5 - 2 = 3 which is equal to dist. The total cost is nums[0] + nums[2] + nums[5] which is 1 + 2 + 2 = 5.
// It can be shown that there is no possible way to divide nums into 3 subarrays at a cost lower than 5.
// Example 2:

// Input: nums = [10,1,2,2,2,1], k = 4, dist = 3
// Output: 15
// Explanation: The best possible way to divide nums into 4 subarrays is: [10], [1], [2], and [2,2,1]. This choice is valid because ik-1 - i1 is 3 - 1 = 2 which is less than dist. The total cost is nums[0] + nums[1] + nums[2] + nums[3] which is 10 + 1 + 2 + 2 = 15.
// The division [10], [1], [2,2,2], and [1] is not valid, because the difference between ik-1 and i1 is 5 - 1 = 4, which is greater than dist.
// It can be shown that there is no possible way to divide nums into 4 subarrays at a cost lower than 15.
// Example 3:

// Input: nums = [10,8,18,9], k = 3, dist = 1
// Output: 36
// Explanation: The best possible way to divide nums into 4 subarrays is: [10], [8], and [18,9]. This choice is valid because ik-1 - i1 is 2 - 1 = 1 which is equal to dist.The total cost is nums[0] + nums[1] + nums[2] which is 10 + 8 + 18 = 36.
// The division [10], [8,18], and [9] is not valid, because the difference between ik-1 and i1 is 3 - 1 = 2, which is greater than dist.
// It can be shown that there is no possible way to divide nums into 3 subarrays at a cost lower than 36.
 

// Constraints:

// 3 <= n <= 105
// 1 <= nums[i] <= 109
// 3 <= k <= n
// k - 2 <= dist <= n - 2



// 🚀 Approach
// Data Structures Used
//     Two balanced sets:
//         kMinEls: stores the smallest (k - 1) elements in the current window.
//         remEls: stores the remaining elements of the window.
//     These sets allow efficient insertion, deletion, and retrieval of min/max elements.
// Initialization
//     Start from index 1 (since nums[0] is always added at the end).
//     Fill the first window until i - dist < 1.
//     Keep only (k - 1) smallest elements in kMinEls, move others to remEls.
// Sliding Window
//     For each new element nums[i], insert it into kMinEls.
//     If kMinEls exceeds size (k-1), move the largest element to remEls.
//     Update the running sum of elements in kMinEls.
//     Track the minimum sum across all windows.
// Window Maintenance
//     Remove the element that slides out (nums[i - dist]).
//     If it was in kMinEls, adjust the sum and replace it with the smallest element from remEls.
//     Otherwise, just erase it from remEls.
// Final answer is nums[0] + res, where res is the minimum sum of (k-1) elements across all valid windows.

// 🕛 Complexity
// Time complexity: O(nlogn)
// Space complexity: O(n)









import java.util.*;

class Solution {
    static class Pair implements Comparable<Pair> {
        long val;
        int idx;

        Pair(long val, int idx) {
            this.val = val;
            this.idx = idx;
        }

        @Override
        public int compareTo(Pair other) {
            if (this.val != other.val) {
                return Long.compare(this.val, other.val);
            }
            return Integer.compare(this.idx, other.idx);
        }
    }

    public long minimumCost(int[] nums, int k, int dist) {
        int n = nums.length;
        TreeSet<Pair> kMinEls = new TreeSet<>();
        TreeSet<Pair> remEls = new TreeSet<>();

        long sum = 0;
        int i = 1;

        // Initialize first window
        while (i - dist < 1) {
            Pair p = new Pair(nums[i], i);
            kMinEls.add(p);
            sum += nums[i];

            if (kMinEls.size() > k - 1) {
                Pair t = kMinEls.last();
                sum -= t.val;
                remEls.add(t);
                kMinEls.remove(t);
            }
            i++;
        }

        long res = Long.MAX_VALUE;
        while (i < n) {
            Pair p = new Pair(nums[i], i);
            kMinEls.add(p);
            sum += nums[i];

            if (kMinEls.size() > k - 1) {
                Pair t = kMinEls.last();
                sum -= t.val;
                remEls.add(t);
                kMinEls.remove(t);
            }

            res = Math.min(res, sum);

            Pair rem = new Pair(nums[i - dist], i - dist);

            if (kMinEls.contains(rem)) {
                kMinEls.remove(rem);
                sum -= rem.val;

                if (!remEls.isEmpty()) {
                    Pair t = remEls.first();
                    kMinEls.add(t);
                    sum += t.val;
                    remEls.remove(t);
                }
            } else {
                remEls.remove(rem);
            }

            i++;
        }
        return nums[0] + res;
    }
}