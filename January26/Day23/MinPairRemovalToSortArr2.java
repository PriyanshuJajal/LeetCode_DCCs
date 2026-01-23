// LEETCODE 3510. Minimum Pair Removal to Sort Array II

// Given an array nums, you can perform the following operation any number of times:

// Select the adjacent pair with the minimum sum in nums. If multiple such pairs exist, choose the leftmost one.
// Replace the pair with their sum.
// Return the minimum number of operations needed to make the array non-decreasing.

// An array is said to be non-decreasing if each element is greater than or equal to its previous element (if it exists).

 

// Example 1:

// Input: nums = [5,2,3,1]

// Output: 2

// Explanation:

// The pair (3,1) has the minimum sum of 4. After replacement, nums = [5,2,4].
// The pair (2,4) has the minimum sum of 6. After replacement, nums = [5,6].
// The array nums became non-decreasing in two operations.

// Example 2:

// Input: nums = [1,2,2]

// Output: 0

// Explanation:

// The array nums is already sorted.

 

// Constraints:

// 1 <= nums.length <= 105
// -109 <= nums[i] <= 109


// 🚀 Approach
// 1. Initialization:
//     - Convert the input into a long long array t to avoid overflow.
//     - Maintain prevIdx and nxtIdx arrays to simulate a linked list of indices for efficient merging.
//     - Use a set (ordered by pair sum) to quickly find the pair with the smallest sum.
// 2. Counting bad pairs:
//     - Initially, count how many adjacent pairs are "bad" (t[i] > t[i+1]).
//     - Insert all adjacent pairs into the set with their sum as the key.
// 3. Iterative merging:    
//     - While there are bad pairs:
//         - Pick the pair with the smallest sum from the set.
//         - Merge them into one element (update t[first] += t[second]).
//         - Update prevIdx and nxtIdx to maintain the linked list structure.
//         - Adjust badPairs count based on neighbors (left and right).
//         - Update the set with new pair sums after merging.
//         - Increment the operation counter ops.
// 4. Once no bad pairs remain, return the number of operations performed.


// 🕛 Complexity
// Time Complexity: O(nlog n).
// Space Complexity: O(n).









import java.util.*;

class Solution {
    static class Pair implements Comparable<Pair> {
        long sum;
        int index;
        Pair(long sum, int index) {
            this.sum = sum;
            this.index = index;
        }
        @Override
        public int compareTo(Pair other) {
            if (this.sum != other.sum) {
                return Long.compare(this.sum, other.sum);
            }
            return Integer.compare(this.index, other.index);
        }
        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (!(o instanceof Pair)) return false;
            Pair p = (Pair) o;
            return sum == p.sum && index == p.index;
        }
        @Override
        public int hashCode() {
            return Objects.hash(sum, index);
        }
    }

    public int minimumPairRemoval(int[] nums) {
        int n = nums.length;
        long[] t = new long[n];
        for (int i = 0; i < n; i++) {
            t[i] = nums[i];
        }

        TreeSet<Pair> minPairSet = new TreeSet<>();
        int[] nxtIdx = new int[n];
        int[] prevIdx = new int[n];

        for (int i = 0; i < n; i++) {
            nxtIdx[i] = i + 1;
            prevIdx[i] = i - 1;
        }

        int badPairs = 0;
        for (int i = 0; i < n - 1; i++) {
            if (t[i] > t[i + 1]) badPairs++;
            minPairSet.add(new Pair(t[i] + t[i + 1], i));
        }

        int ops = 0;
        while (badPairs > 0) {
            Pair p = minPairSet.pollFirst(); 
            int first = p.index;
            int second = nxtIdx[first];

            int leftFirst = prevIdx[first];
            int rightSecond = nxtIdx[second];

            if (t[first] > t[second]) badPairs--;

            if (leftFirst >= 0) {
                if (t[leftFirst] > t[first] && t[leftFirst] <= t[first] + t[second]) {
                    badPairs--;
                } else if (t[leftFirst] <= t[first] && t[leftFirst] > t[first] + t[second]) {
                    badPairs++;
                }
            }

            if (rightSecond < n) {
                if (t[rightSecond] >= t[second] && t[rightSecond] < t[first] + t[second]) {
                    badPairs++;
                } else if (t[rightSecond] < t[second] && t[rightSecond] >= t[first] + t[second]) {
                    badPairs--;
                }
            }

            if (leftFirst >= 0) {
                minPairSet.remove(new Pair(t[leftFirst] + t[first], leftFirst));
                minPairSet.add(new Pair(t[leftFirst] + t[first] + t[second], leftFirst));
            }

            if (rightSecond < n) {
                minPairSet.remove(new Pair(t[second] + t[rightSecond], second));
                minPairSet.add(new Pair(t[first] + t[second] + t[rightSecond], first));
                prevIdx[rightSecond] = first;
            }

            nxtIdx[first] = rightSecond;
            t[first] += t[second];
            ops++;
        }
        return ops;
    }
}