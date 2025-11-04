// LEETCODE 3318. Find X-Sum of All K-Long Subarrays I



// You are given an array nums of n integers and two integers k and x.

// The x-sum of an array is calculated by the following procedure:

// Count the occurrences of all elements in the array.
// Keep only the occurrences of the top x most frequent elements. If two elements have the same number of occurrences, the element with the bigger value is considered more frequent.
// Calculate the sum of the resulting array.
// Note that if an array has less than x distinct elements, its x-sum is the sum of the array.

// Return an integer array answer of length n - k + 1 where answer[i] is the x-sum of the subarray nums[i..i + k - 1].

 

// Example 1:

// Input: nums = [1,1,2,2,3,4,2,3], k = 6, x = 2

// Output: [6,10,12]

// Explanation:

// For subarray [1, 1, 2, 2, 3, 4], only elements 1 and 2 will be kept in the resulting array. Hence, answer[0] = 1 + 1 + 2 + 2.
// For subarray [1, 2, 2, 3, 4, 2], only elements 2 and 4 will be kept in the resulting array. Hence, answer[1] = 2 + 2 + 2 + 4. Note that 4 is kept in the array since it is bigger than 3 and 1 which occur the same number of times.
// For subarray [2, 2, 3, 4, 2, 3], only elements 2 and 3 are kept in the resulting array. Hence, answer[2] = 2 + 2 + 2 + 3 + 3.
// Example 2:

// Input: nums = [3,8,7,8,7,5], k = 2, x = 2

// Output: [11,15,15,15,12]

// Explanation:

// Since k == x, answer[i] is equal to the sum of the subarray nums[i..i + k - 1].

 

// Constraints:

// 1 <= n == nums.length <= 50
// 1 <= nums[i] <= 50
// 1 <= x <= k <= nums.length





// 🚀 Approach
// Initialize a frequency map for the first window of size k.
// For each window:
//     Build a max heap (Priority Queue) using {frequency, number} pairs.
//     Extract the top x elements from the heap and compute the weighted sum.
//     Slide the window:
//         Decrease frequency of the outgoing element.
//         Increase frequency of the incoming element.
// Store the result for each window in a result vector.
// This approach avoids redundant recomputation and leverages efficient data structures for frequency tracking and top-k extraction.



// 🕛 Complexity
// Time complexity: O(n * klogk)
// Outer loop runs O(n -k + 1) ~ O(n)
// For each window:
// Frequency map update: O(1)
// Heap construction: O(klog k)
// Top x extraction: O(xlog k)
// Space complexity: O(k)
// Frequency map stores up to k unique elements.
// Heap stores up to k elements per window.
// Result vector stores n - k + 1 integers











class Solution {
    public int[] findXSum(int[] nums, int k, int x) {
        int n = nums.length;
        List<Integer> res = new ArrayList<>();
        Map<Integer , Integer> mp = new HashMap<>();

        for (int i = 0; i < k; i++) {
            mp.put(nums[i] , mp.getOrDefault(nums[i] , 0) + 1);
        }

        for (int i = 0; i <= n - k; i++) {
            PriorityQueue<int[]> pq = new PriorityQueue<>((a , b) -> {
               if (b[0] != a[0]) return b[0] - a[0];
               return b[1] - a[1];
            });
            
            for (Map.Entry<Integer  , Integer> entry : mp.entrySet()) {
                pq.offer(new int[] {entry.getValue() , entry.getKey()});
            }
            
            int sum = 0;
            int cnt = 0;
            while(cnt < x && !pq.isEmpty()) {
                int[] top = pq.poll();
                sum += top[0] * top[1];
                cnt++;
            }
            res.add(sum);

            if (i + k < n) {
                int out = nums[i];
                int in = nums[i + k];
                mp.put(out , mp.get(out) - 1);
                if (mp.get(out) == 0) mp.remove(out);

                mp.put(in , mp.getOrDefault(in , 0) + 1);
            }
        }
        return res.stream().mapToInt(Integer::intValue).toArray();
    }
}