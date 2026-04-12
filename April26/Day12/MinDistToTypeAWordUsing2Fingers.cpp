// LEETCODE 1320. Minimum Distance to Type a Word Using Two Fingers

// You have a keyboard layout as shown above in the X-Y plane, where each English uppercase letter is located at some coordinate.

// For example, the letter 'A' is located at coordinate (0, 0), the letter 'B' is located at coordinate (0, 1), the letter 'P' is located at coordinate (2, 3) and the letter 'Z' is located at coordinate (4, 1).
// Given the string word, return the minimum total distance to type such string using only two fingers.

// The distance between coordinates (x1, y1) and (x2, y2) is |x1 - x2| + |y1 - y2|.

// Note that the initial positions of your two fingers are considered free so do not count towards your total distance, also your two fingers do not have to start at the first letter or the first two letters.

 

// Example 1:

// Input: word = "CAKE"
// Output: 3
// Explanation: Using two fingers, one optimal way to type "CAKE" is: 
// Finger 1 on letter 'C' -> cost = 0 
// Finger 1 on letter 'A' -> cost = Distance from letter 'C' to letter 'A' = 2 
// Finger 2 on letter 'K' -> cost = 0 
// Finger 2 on letter 'E' -> cost = Distance from letter 'K' to letter 'E' = 1 
// Total distance = 3
// Example 2:

// Input: word = "HAPPY"
// Output: 6
// Explanation: Using two fingers, one optimal way to type "HAPPY" is:
// Finger 1 on letter 'H' -> cost = 0
// Finger 1 on letter 'A' -> cost = Distance from letter 'H' to letter 'A' = 2
// Finger 2 on letter 'P' -> cost = 0
// Finger 2 on letter 'P' -> cost = Distance from letter 'P' to letter 'P' = 0
// Finger 1 on letter 'Y' -> cost = Distance from letter 'A' to letter 'Y' = 4
// Total distance = 6
 

// Constraints:

// 2 <= word.length <= 300
// word consists of uppercase English letters.



// 🚀 Approach
// Keyboard Layout
//     The letters A-Z are placed on a grid with 6 columns.
//     Position of a letter is computed by pos / 6 (row) and pos % 6 (column).
//     Distance between two letters is the Manhattan distance:
//     |x1 - x2| + |y1 - y2|
// State Definition
//     dp[i][f1][f2] = minimum distance needed to type the substring starting at index i when finger1 is on f1 and finger2 is on f2.
//     f1 and f2 range from 0–25 for letters, and 26 means “not used yet”.
// Transitions
//     At each character word[i], we can either:
//         Move finger1 to press it, incurring getDist(f1, curr).
//         Move finger2 to press it, incurring getDist(f2, curr).
//     If a finger hasn’t been used yet (=26), moving it costs 0.
// Recursion + Memoization
//     Use recursion (solve) with memoization (dp) to explore both choices.
//     Base case: if i == word.length(), return 0.
// Start with both fingers unused (f1 = 26, f2 = 26).
// The result is solve(word, 0, 26, 26).

// 🕛 Complexity
// Time complexity: O(n * 27 * 27)
// Space complexity: O(n * 27 * 27)



class Solution {
public:
    int dp[301][27][27];

    pair<int , int> getCoordinate(int pos) {
        return {pos / 6 , pos % 6};
    }

    int getDist(int pos1 , int pos2) {
        auto [x1 , y1] = getCoordinate(pos1);
        auto [x2 , y2] = getCoordinate(pos2);

        return abs(x1 - x2) + abs(y1 - y2);
    }

    int solve(string& word , int i , int f1 , int f2) {
        if (i >= word.length()) return 0;

        if (dp[i][f1][f2] != -1) {
            return dp[i][f1][f2];
        }

        int curr = word[i] - 'A'; 

        // if no finger is used
        if (f1 == 26 && f2 == 26) {
            return dp[i][f1][f2] = solve(word , i + 1 , curr , f2);
        }

        // f2 (finger 2) not used
        if (f2 == 26) {
            int useF2 = 0 + solve(word , i + 1 , f1 , curr);
            int useF1 = getDist(f1 , curr) + solve(word , i + 1 , curr , f2);

            return dp[i][f1][f2] = min(useF2 , useF1);
        }

        // both fingers used
        int useF1 = getDist(f1 , curr) + solve(word , i + 1 , curr , f2);
        int useF2 = getDist(f2 , curr) + solve(word , i + 1 , f1 , curr);

        return dp[i][f1][f2] = min(useF1 , useF2);        
    }

    int minimumDistance(string word) {
        memset(dp , -1 , sizeof(dp));
        return solve(word , 0 , 26 , 26);
    }
};