// LEETCODE 1356. Sort Integers by The Number of 1 Bits

// You are given an integer array arr. Sort the integers in the array in ascending order by the number of 1's in their binary representation and in case of two or more integers have the same number of 1's you have to sort them in ascending order.

// Return the array after sorting it.

 

// Example 1:

// Input: arr = [0,1,2,3,4,5,6,7,8]
// Output: [0,1,2,4,8,3,5,6,7]
// Explantion: [0] is the only integer with 0 bits.
// [1,2,4,8] all have 1 bit.
// [3,5,6] have 2 bits.
// [7] has 3 bits.
// The sorted array by bits is [0,1,2,4,8,3,5,6,7]
// Example 2:

// Input: arr = [1024,512,256,128,64,32,16,8,4,2,1]
// Output: [1,2,4,8,16,32,64,128,256,512,1024]
// Explantion: All integers have 1 bit in the binary representation, you should just sort them in ascending order.
 

// Constraints:

// 1 <= arr.length <= 500
// 0 <= arr[i] <= 104



// 🚀 Approach
// Use __builtin_popcount(x) to quickly count the number of 1s in the binary form of x.
// Define a lambda comparator:
//     Compare two numbers first by their popcount.
//     If equal, compare by their numeric value.
// Apply sort with this comparator.
// Return the sorted array.

// 🕛 Complexity
// Time complexity: O(nlogn)
// Space complexity: O(1)









class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        auto lambda = [](int& a , int& b) {
            int cnt1InA = __builtin_popcount(a);
            int cnt1InB = __builtin_popcount(b);

            if (cnt1InA == cnt1InB) return a < b;
            return cnt1InA < cnt1InB;
        };
        sort(begin(arr) , end(arr) , lambda);

        return arr;
    }
};