// LEETCODE 679. 24 Game

// You are given an integer array cards of length 4. You have four cards, each containing a number in the range [1, 9]. You should arrange the numbers on these cards in a mathematical expression using the operators ['+', '-', '*', '/'] and the parentheses '(' and ')' to get the value 24.

// You are restricted with the following rules:

// The division operator '/' represents real division, not integer division.
// For example, 4 / (1 - 2 / 3) = 4 / (1 / 3) = 12.
// Every operation done is between two numbers. In particular, we cannot use '-' as a unary operator.
// For example, if cards = [1, 1, 1, 1], the expression "-1 - 1 - 1 - 1" is not allowed.
// You cannot concatenate numbers together
// For example, if cards = [1, 2, 1, 2], the expression "12 + 12" is not valid.
// Return true if you can get such expression that evaluates to 24, and false otherwise.

 

// Example 1:

// Input: cards = [4,1,8,7]
// Output: true
// Explanation: (8-4) * (7-1) = 24
// Example 2:

// Input: cards = [1,2,1,2]
// Output: false
 

// Constraints:

// cards.length == 4
// 1 <= cards[i] <= 9


// 🚀 Approach
// Permutations:
    // Try all 4! = 24 permutations of the input cards.
    // This ensures we consider every possible order of applying operations.
// Recursive Reduction:
    // Reduce the 4 numbers to 3 by applying one operation to a pair.
    // Then reduce 3 to 2, and finally check if any 2-number operation yields 24.
// Floating Point Precision:
    // Use abs(result - 24) <= 1e-5 to account for rounding errors in division.
// Recursive Functions:
    // isValid(vector& cards) → handles 4 numbers.
    // isValid(double a, double b, double c) → handles 3 numbers.
    // isValid(double a, double b) → base case for 2 numbers.
// Short-Circuiting:    
    // If any recursive path returns true, we stop and return true.


class Solution {
public:
    bool isValid(vector<int>& cards) {
        double a = cards[0] , b = cards[1] , c = cards[2] , d = cards[3];
        if (isValid(a + b , c , d) || isValid(a - b , c , d) || isValid(a * b , c , d) || isValid(a / b , c , d)) return true;
        if (isValid(a , b + c , d) || isValid(a , b - c , d) || isValid(a , b * c , d) || isValid(a , b / c , d)) return true;
        if (isValid(a , b , c + d) || isValid(a , b , c - d) || isValid(a , b , c * d) || isValid(a , b , c / d)) return true;

        return false;
    }

    bool isValid(double a , double b , double c) {
        if (isValid(a + b , c) || isValid(a - b , c) || isValid(a * b , c) || b && isValid(a / b , c)) return true;
        if (isValid(a , b + c) || isValid(a , b - c) || isValid(a , b * c) || c && isValid(a , b / c)) return true;

        return false;
    }

    bool isValid(double a , double b) {
        if (abs(a + b - 24) <= 1e-5 || abs(a - b - 24) <= 1e-5 || abs(a * b - 24) <= 1e-5 || b &&abs(a / b - 24) <= 1e-5) return true;

        return false;
    }

    bool judgePoint24(vector<int>& cards) {
        sort(begin(cards) , end(cards));
        if (isValid(cards)) return true;

        while(next_permutation(begin(cards) , end(cards))) {
            if (isValid(cards)) return true;
        }
        return false;
    }
};