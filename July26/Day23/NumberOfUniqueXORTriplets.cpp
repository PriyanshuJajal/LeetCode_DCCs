// LEETCODE 3513. Number of Unique XOR Triplets I

// Time complexity: O(logn)
// Space complexity: O(1)



class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) return n;

        int triplets = 2;
        while(triplets <= n) {
            triplets <<= 1;
        }
        
        return triplets;
    }
};