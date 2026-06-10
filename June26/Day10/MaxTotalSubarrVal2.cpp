// LEETCODE 3691. Maximum Total Subarray Value II

// You are given an integer array nums of length n and an integer k.

// You must select exactly k distinct non-empty subarrays nums[l..r] of nums. Subarrays may overlap, but the exact same subarray (same l and r) cannot be chosen more than once.

// The value of a subarray nums[l..r] is defined as: max(nums[l..r]) - min(nums[l..r]).

// The total value is the sum of the values of all chosen subarrays.

// Return the maximum possible total value you can achieve.

 

// Example 1:

// Input: nums = [1,3,2], k = 2

// Output: 4

// Explanation:

// One optimal approach is:

// Choose nums[0..1] = [1, 3]. The maximum is 3 and the minimum is 1, giving a value of 3 - 1 = 2.
// Choose nums[0..2] = [1, 3, 2]. The maximum is still 3 and the minimum is still 1, so the value is also 3 - 1 = 2.
// Adding these gives 2 + 2 = 4.

// Example 2:

// Input: nums = [4,2,5,1], k = 3

// Output: 12

// Explanation:

// One optimal approach is:

// Choose nums[0..3] = [4, 2, 5, 1]. The maximum is 5 and the minimum is 1, giving a value of 5 - 1 = 4.
// Choose nums[1..3] = [2, 5, 1]. The maximum is 5 and the minimum is 1, so the value is also 4.
// Choose nums[2..3] = [5, 1]. The maximum is 5 and the minimum is 1, so the value is again 4.
// Adding these gives 4 + 4 + 4 = 12.

 

// Constraints:

// 1 <= n == nums.length <= 5 * 10​​​​​​​4
// 0 <= nums[i] <= 109
// 1 <= k <= min(105, n * (n + 1) / 2)


// 🚀 Approach
// Segment Tree Construction
//     Build a segment tree that stores both max and min for every interval.
//     This allows us to query max(nums[l..r]) and min(nums[l..r]) in O(log n).
// Heap Initialization
//     For each starting index l, compute the value of the longest subarray [l..n - 1].
//     Push (value, l, r) into a max heap.
// Heap Processing (k times)
//     Pop the largest (val, l, r) from the heap.
//     Add val to the answer.
//     If r > l, shrink the subarray to [l..r - 1] and push its value into the heap.
//     This ensures we always pick the next best candidate.
// After k iterations, the accumulated sum is the maximum possible.

// 🕛 Complexity
// Time complexity: O((n + k) * logn)
// Space complexity: O(n)


class SegTree {
    vector<int> maxVal , minVal;
    int n ;

public:
    SegTree(vector<int>& nums) {
        n = nums.size();
        maxVal.resize(n * 4);
        minVal.resize(n * 4);
        build(1 , 0 , n - 1 , nums);
    }

    void build(int node , int l , int r , vector<int>& nums) {
        if (l == r) {
            maxVal[node] = minVal[node] = nums[l];
            return;
        }

        int m = (l + r) / 2;
        build(node * 2 , l , m , nums);
        build(node * 2 + 1 , m + 1 , r , nums);

        maxVal[node] = max(maxVal[node * 2] , maxVal[node * 2 + 1]);
        minVal[node] = min(minVal[node * 2] , minVal[node * 2 + 1]); 
    }

    int queryMax(int node , int l , int r , int ql , int qr) {
        if (ql <= l && r <= qr) {
            return maxVal[node];
        }

        int m = (l + r) / 2;
        int res = INT_MIN;

        if (ql <= m) {
            res = max(res , queryMax(node * 2 , l , m , ql , qr));
        }
        if (qr > m) {
            res = max(res , queryMax(node * 2 + 1 , m + 1 , r , ql , qr));
        }

        return res;
    }

    int queryMin(int node , int l , int r , int ql , int qr) {
        if (ql <= l && r <= qr) {
            return minVal[node];
        }

        int m = (l + r) / 2;
        int res = INT_MAX;

        if (ql <= m) {
            res = min(res , queryMin(node * 2 , l , m , ql , qr));
        }

        if (qr > m) {
            res = min(res , queryMin(node * 2 + 1 , m + 1 , r , ql , qr));
        }

        return res;
    }
};

class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int n = nums.size();
        SegTree seg(nums);
        priority_queue<tuple<int , int , int>> pq;

        for (int l = 0; l < n; l++) {
            pq.emplace(seg.queryMax(1 , 0 , n - 1 , l , n - 1) -
                        seg.queryMin(1 , 0 , n - 1 , l , n - 1) , l , n - 1);
        }

        long long maxTotalVal = 0;
        while(k--) {
            auto [val , l , r] = pq.top();
            pq.pop();

            maxTotalVal += val;

            if (r > l) {
                pq.emplace(seg.queryMax(1 , 0 , n - 1 , l , r - 1) - 
                            seg.queryMin(1 , 0 , n - 1 , l , r - 1) , l , r - 1);
            }
        }

        return maxTotalVal;
    }
};