// LEETCODE 1304. Find N Unique Integers Sum up to Zero

// Given an integer n, return any array containing n unique integers such that they add up to 0.

 

// Example 1:

// Input: n = 5
// Output: [-7,-1,1,3,4]
// Explanation: These arrays also are accepted [-5,-1,1,2,3] , [-3,-1,2,-2,4].
// Example 2:

// Input: n = 3
// Output: [-1,0,1]
// Example 3:

// Input: n = 1
// Output: [0]
 

// Constraints:

// 1 <= n <= 1000


// 🚀 Approach
// Initialize an integer array res.
// Use a pointer idx(in Java) to track the current index in the array.
// Loop from 1 to n/2:
//     Add i and -i to the array.
//     This gives us pairs like (1, -1), (2, -2), ... which cancel each other out.
//     If n is odd, add 0 to the array at the end.
// Return the array res.
// This guarantees:
//     All elements are unique.
//     The total sum is zero.
//     The array has exactly n elements.



class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> res;
        for (int i = 1; i <= n / 2; i++) {
            res.push_back(i);
            res.push_back(-i);
        }
        
        if (n % 2 == 0) return res;
        else res.push_back(0);
        return res;
    }
};