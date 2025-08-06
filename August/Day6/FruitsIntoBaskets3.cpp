// LEETCODE 3479...

// You are given two arrays of integers, fruits and baskets, each of length n, where fruits[i] represents the quantity of the ith type of fruit, and baskets[j] represents the capacity of the jth basket.

// From left to right, place the fruits according to these rules:

// Each fruit type must be placed in the leftmost available basket with a capacity greater than or equal to the quantity of that fruit type.
// Each basket can hold only one type of fruit.
// If a fruit type cannot be placed in any basket, it remains unplaced.
// Return the number of fruit types that remain unplaced after all possible allocations are made.

 

// Example 1:

// Input: fruits = [4,2,5], baskets = [3,5,4]

// Output: 1

// Explanation:

// fruits[0] = 4 is placed in baskets[1] = 5.
// fruits[1] = 2 is placed in baskets[0] = 3.
// fruits[2] = 5 cannot be placed in baskets[2] = 4.
// Since one fruit type remains unplaced, we return 1.

// Example 2:

// Input: fruits = [3,6,1], baskets = [6,4,7]

// Output: 0

// Explanation:

// fruits[0] = 3 is placed in baskets[0] = 6.
// fruits[1] = 6 cannot be placed in baskets[1] = 4 (insufficient capacity) but can be placed in the next available basket, baskets[2] = 7.
// fruits[2] = 1 is placed in baskets[1] = 4.
// Since all fruits are successfully placed, we return 0.

 

// Constraints:

// n == fruits.length == baskets.length
// 1 <= n <= 105
// 1 <= fruits[i], baskets[i] <= 109

// Approach...
// - Build Segment Tree
// - Construct a segment tree on the baskets array.
// - Each node stores the maximum capacity within its range.
// - Process Each Fruit
// - For every fruit:
// - Use the segment tree to find the leftmost basket with capacity ≥ fruit size.
// - This is done using a recursive search.
// - Update Tree After Placement
// - If a valid basket is found:
// - Mark it as used by setting its value to -1.
// - Update the segment tree to reflect this change.
// - Count Unplaced Fruits
// - If no basket can hold a fruit, increment the unplaced counter.
// - Return Final Answer
// - After placing all fruits, return the count of those that remained unplaced.


class Solution {
private:
    vector<int> seg;
    void build(vector<int>& baskets, int idx, int low, int high) {
        if (low == high) {
            seg[idx] = baskets[low];
            return;
        }
        int mid = (low + high) >> 1;
        build(baskets, 2 * idx + 1, low, mid);
        build(baskets, 2 * idx + 2, mid + 1, high);
        seg[idx] = max(seg[2 * idx + 1], seg[2 * idx + 2]);
    }

    int search(int idx, int low, int high, int k) {
        if (seg[idx] < k)
            return -1;
        if (low == high) {
            seg[idx] = -1;
            return low;
        }
        int mid = (low + high) >> 1;
        int pos;
        if (seg[2 * idx + 1] >= k)
            pos = search(2 * idx + 1, low, mid, k);
        else
            pos = search(2 * idx + 2, mid + 1, high, k);
        seg[idx] = max(seg[2 * idx + 1], seg[2 * idx + 2]);
        return pos;
    }
    
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        int ans = 0;
        seg.assign(4 * n, 0);
        build(baskets, 0, 0, n - 1);
        for (auto fruit : fruits)
            if (search(0, 0, n - 1, fruit) == -1)
                ans++;
        return ans;
    }
};