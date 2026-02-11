// LEETCODE 3721. Longest Balanced Subarray II

// You are given an integer array nums.

// A subarray is called balanced if the number of distinct even numbers in the subarray is equal to the number of distinct odd numbers.

// Return the length of the longest balanced subarray.

 

// Example 1:

// Input: nums = [2,5,4,3]

// Output: 4

// Explanation:

// The longest balanced subarray is [2, 5, 4, 3].
// It has 2 distinct even numbers [2, 4] and 2 distinct odd numbers [5, 3]. Thus, the answer is 4.
// Example 2:

// Input: nums = [3,2,2,5,4]

// Output: 5

// Explanation:

// The longest balanced subarray is [3, 2, 2, 5, 4].
// It has 2 distinct even numbers [2, 4] and 2 distinct odd numbers [3, 5]. Thus, the answer is 5.
// Example 3:

// Input: nums = [1,2,3,2]

// Output: 3

// Explanation:

// The longest balanced subarray is [2, 3, 2].
// It has 1 distinct even number [2] and 1 distinct odd number [3]. Thus, the answer is 3.
 

// Constraints:

// 1 <= nums.length <= 105
// 1 <= nums[i] <= 105

// 🚀 Approach
// 1. Prefix Sum Encoding
//     - Compute prefix sums where each number contributes +1 (even) or -1 (odd).
//     - Store occurrences of each number to know when its next appearance is.
// 2. Segment Tree Construction
//     - Build a segment tree over the prefix sums.
//     - Each node stores the minimum and maximum values in its range, plus a lazy tag for range updates.
// 3. Finding Balanced Subarrays
//     - For each index i, query the segment tree to find the last position where the prefix sum equals 0.
//     - This gives the length of the balanced subarray starting at i.
// 4. Lazy Updates
//     - When moving past an element, adjust prefix sums in the segment tree for the range until its next occurrence.
//     - This ensures the balance condition is correctly maintained.
// 5. Track the maximum length found across all indices.


// 🕛 Complexity
// Time Complexity:
//     - Building the segment tree: O(n)
//     - Each update and query: O(log n)
//     - For all elements: O(nlog n)

// Space Complexity:
//     - Segment tree storage: O(n)
//     - Prefix sums and occurrence map: O(n)
//     - Overall: O(n)









struct LazyTag {
    int toAdd = 0;

    LazyTag& operator+=(const LazyTag& other) {
        this->toAdd += other.toAdd;
        return *this;
    }

    bool hasTag() const {
        return toAdd != 0;
    }

    void clear() { toAdd = 0; }
};

struct SegmentTreeNode {
    int minVal = 0;
    int maxVal = 0;
    LazyTag lazy_tag;
};

class SegmentTree {
public:
    int n;
    vector<SegmentTreeNode> tree;

    SegmentTree(const vector<int>& data) : n(data.size()) {
        tree.resize(n * 4 + 1);
        build(data , 1 , n , 1);
    }

    void add(int l, int r, int val) {
        LazyTag tag{val};
        update(l , r , tag , 1 , n , 1);
    }

    int findLast(int start, int val) {
        if (start > n) {
            return -1;
        }
        return find(start , n , val , 1 , n , 1);
    }

private:
    inline void applyTag(int i, const LazyTag& tag) {
        tree[i].minVal += tag.toAdd;
        tree[i].maxVal += tag.toAdd;
        tree[i].lazy_tag += tag;
    }

    inline void pushdown(int i) {
        if (tree[i].lazy_tag.hasTag()) {
            LazyTag tag = tree[i].lazy_tag;
            applyTag(i << 1, tag);
            applyTag(i << 1 | 1 , tag);
            tree[i].lazy_tag.clear();
        }
    }

    inline void pushup(int i) {
        tree[i].minVal =
            std::min(tree[i << 1].minVal , tree[i << 1 | 1].minVal);
        tree[i].maxVal =
            std::max(tree[i << 1].maxVal , tree[i << 1 | 1].maxVal);
    }

    void build(const vector<int>& data, int l, int r, int i) {
        if (l == r) {
            tree[i].minVal = tree[i].maxVal = data[l - 1];
            return;
        }

        int mid = l + ((r - l) >> 1);
        build(data , l , mid , i << 1);
        build(data , mid + 1 , r , i << 1 | 1);

        pushup(i);
    }

    void update(int targetL, int targetR, const LazyTag& tag, int l, int r,
                int i) {
        if (targetL <= l && r <= targetR) {
            applyTag(i, tag);
            return;
        }

        pushdown(i);
        int mid = l + ((r - l) >> 1);
        if (targetL <= mid) update(targetL , targetR , tag , l , mid , i << 1);
        if (targetR > mid)
            update(targetL , targetR , tag , mid + 1 , r , i << 1 | 1);
        pushup(i);
    }

    int find(int targetL, int targetR, int val, int l, int r, int i) {
        if (tree[i].minVal > val || tree[i].maxVal < val) {
            return -1;
        }

        // according to the Intermediate Value Theorem, there must be a solution
        // within this interval.
        if (l == r) {
            return l;
        }

        pushdown(i);
        int mid = l + ((r - l) >> 1);

        // targetL is definitely less than or equal to r (= n)
        if (targetR >= mid + 1) {
            int res = find(targetL, targetR, val, mid + 1, r, i << 1 | 1);
            if (res != -1) return res;
        }

        if (l <= targetR && mid >= targetL) {
            return find(targetL, targetR, val, l, mid, i << 1);
        }

        return -1;
    }
};

class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        map<int, queue<int>> occurrences;
        auto sgn = [](int x) { return (x % 2) == 0 ? 1 : -1; };

        int len = 0;
        vector<int> prefSum(nums.size(), 0);

        prefSum[0] = sgn(nums[0]);
        occurrences[nums[0]].push(1);

        for (int i = 1; i < nums.size(); i++) {
            prefSum[i] = prefSum[i - 1];
            auto& occ = occurrences[nums[i]];
            if (occ.empty()) {
                prefSum[i] += sgn(nums[i]);
            }
            occ.push(i + 1);
        }

        SegmentTree seg(prefSum);

        for (int i = 0; i < nums.size(); i++) {
            len = std::max(len, seg.findLast(i + len, 0) - i);

            auto nxtPos = nums.size() + 1;
            occurrences[nums[i]].pop();
            if (!occurrences[nums[i]].empty()) {
                nxtPos = occurrences[nums[i]].front();
            }

            seg.add(i + 1, nxtPos - 1, -sgn(nums[i]));
        }

        return len;
    }
};