// LEETCODE 166. Fraction to Recurring Decimal

// Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.

// If the fractional part is repeating, enclose the repeating part in parentheses.

// If multiple answers are possible, return any of them.

// It is guaranteed that the length of the answer string is less than 104 for all the given inputs.

 

// Example 1:

// Input: numerator = 1, denominator = 2
// Output: "0.5"
// Example 2:

// Input: numerator = 2, denominator = 1
// Output: "2"
// Example 3:

// Input: numerator = 4, denominator = 333
// Output: "0.(012)"
 

// Constraints:

// -231 <= numerator, denominator <= 231 - 1
// denominator != 0



// 🚀 Approach
// Handle zero numerator and sign of the result.
// Convert numerator and denominator to long value to avoid overflow.
// Append the integer part of the division.
// If there's a remainder, start building the decimal part.
// Use a hash map to store each remainder's position in the result string res.
// If a remainder repeats, insert parentheses around the repeating part.





class Solution {
    public String fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) return "0";

        StringBuilder res = new StringBuilder();
        if ((numerator < 0) ^ (denominator < 0)) res.append("-");

        long num = Math.abs((long)numerator);
        long den = Math.abs((long)denominator);

        res.append(num / den);
        long rem = num % den;

        if (rem == 0) return res.toString();

        res.append(".");
        Map<Long , Integer> remainder = new HashMap<>();

        while(rem != 0) {
            if (remainder.containsKey(rem)) {
                res.insert(remainder.get(rem) , "(");
                res.append(")");
                break;
            }
            remainder.put(rem , res.length());
            rem *= 10;
            res.append(rem / den);
            rem %= den;
        }
        return res.toString();
    }
}