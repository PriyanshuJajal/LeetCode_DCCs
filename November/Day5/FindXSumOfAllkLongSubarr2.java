// LEETCODE 3321. Find X-Sum of All K-Long Subarrays II


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

// nums.length == n
// 1 <= n <= 105
// 1 <= nums[i] <= 109
// 1 <= x <= k <= nums.length




// 🚀 Approach
// Use a frequency map to track how many times each element appears in the current window.
// Maintain 2 multisets (C++) or 2 TreeSets (Java):
//     topX: top x contributors (sorted by frequency and value).
//     st: remaining contributors.
// Rebalance these sets after every update:
//     Ensure topX has exactly x elements.
//     Swap elements between topX and st if a better contributor is available.
// Slide the window:
//     Remove the outgoing element.
//     Add the incoming element.
// Rebalance and record the sum.


// 🕛 Complexity
// Time complexity: O(nlogk)
// Space complexity: O(k)









class Solution {
    static class Pair implements Comparable<Pair> {
        long freq , val;

        Pair(long freq , long val) {
            this.freq = freq;
            this.val = val;
        }

        public int compareTo(Pair other) {
            if (this.freq != other.freq) return Long.compare(this.freq , other.freq);
            return Long.compare(this.val , other.val);
        }

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (!(o instanceof Pair)) return false;
            Pair p = (Pair) o;
            return freq == p.freq && val == p.val;
        }

        @Override
        public int hashCode() {
            return Objects.hash(freq , val);
        }
    }

    TreeSet<Pair> topX = new TreeSet<>();
    TreeSet<Pair> st = new TreeSet<>();
    Map<Integer, Long> freqMap = new HashMap<>();
    long currXSum = 0;
    int xVal;

    void rebalance() {
        int sz = Math.min(xVal , freqMap.size());

        while (topX.size() < sz && !st.isEmpty()) {
            Pair best = st.pollLast();
            topX.add(best);
            currXSum += best.freq * best.val;
        }

        while (topX.size() > sz) {
            Pair worst = topX.pollFirst();
            st.add(worst);
            currXSum -= worst.freq * worst.val;
        }

        while (!topX.isEmpty() && !st.isEmpty() && topX.first().compareTo(st.last()) < 0) {
            Pair worst = topX.pollFirst();
            Pair best = st.pollLast();

            topX.add(best);
            st.add(worst);

            currXSum -= worst.freq * worst.val;
            currXSum += best.freq * best.val;
        }
    }

    void updateEl(int el, int changeFreq) {
        long oldFreq = freqMap.getOrDefault(el, 0L);
        long newFreq = oldFreq + changeFreq;

        Pair oldPair = new Pair(oldFreq , el);
        Pair newPair = new Pair(newFreq , el);

        if (oldFreq > 0) {
            if (topX.remove(oldPair)) {
                currXSum -= oldFreq * el;
            }
            else st.remove(oldPair);
            
        }
        if (newFreq > 0) {
            freqMap.put(el, newFreq);
            st.add(newPair);
        }
        else freqMap.remove(el);

        rebalance();
    }

    public long[] findXSum(int[] nums, int k, int x) {
        int n = nums.length;
        List<Long> ans = new ArrayList<>();

        topX.clear();
        st.clear();
        freqMap.clear();
        currXSum = 0;
        this.xVal = x;

        for (int i = 0; i < k; i++) {
            freqMap.put(nums[i] , freqMap.getOrDefault(nums[i] , 0L) + 1);
        }

        for (Map.Entry<Integer, Long> entry : freqMap.entrySet()) {
            st.add(new Pair(entry.getValue() , entry.getKey()));
        }

        rebalance();
        ans.add(currXSum);

        for (int i = 0; i < n - k; i++) {
            updateEl(nums[i] , -1);
            updateEl(nums[i + k] , 1);
            ans.add(currXSum);
        }

        long[] res = new long[ans.size()];
        for (int i = 0; i < ans.size(); i++) res[i] = ans.get(i);
        return res;
    }
}
