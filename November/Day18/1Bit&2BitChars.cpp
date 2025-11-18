// LEETCODE 717. 1-bit and 2-bit Characters

// We have two special characters:

// The first character can be represented by one bit 0.
// The second character can be represented by two bits (10 or 11).
// Given a binary array bits that ends with 0, return true if the last character must be a one-bit character.

 

// Example 1:

// Input: bits = [1,0,0]
// Output: true
// Explanation: The only way to decode it is two-bit character and one-bit character.
// So the last character is one-bit character.
// Example 2:

// Input: bits = [1,1,1,0]
// Output: false
// Explanation: The only way to decode it is two-bit character and two-bit character.
// So the last character is not one-bit character.
 

// Constraints:

// 1 <= bits.length <= 1000
// bits[i] is either 0 or 1.



// 🚀 Approach
// We iterate through the array using a pointer i. At each step:
//     If bits[i] == 0, it's a one-bit character → move i by 1.
//     If bits[i] == 1, it's the start of a two-bit character → move i by 2.
// We stop the loop at n - 1 because we want to check if the last character is a standalone one-bit character. If i == n - 1 after the loop, it means the last character was decoded as a one-bit character.


// 🕛 Complexity
// Time complexity: O(n)
// Space complexity: O(1)










class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int n = bits.size();
        int i = 0;
        while(i < n - 1) {
            i += bits[i] + 1;
        }
        return i == n - 1;
    }
};