// LEETCODE 1716. Calculate Money in Leetcode Bank

// Hercy wants to save money for his first car. He puts money in the Leetcode bank every day.

// He starts by putting in $1 on Monday, the first day. Every day from Tuesday to Sunday, he will put in $1 more than the day before. On every subsequent Monday, he will put in $1 more than the previous Monday.

// Given n, return the total amount of money he will have in the Leetcode bank at the end of the nth day.

 

// Example 1:

// Input: n = 4
// Output: 10
// Explanation: After the 4th day, the total is 1 + 2 + 3 + 4 = 10.
// Example 2:

// Input: n = 10
// Output: 37
// Explanation: After the 10th day, the total is (1 + 2 + 3 + 4 + 5 + 6 + 7) + (2 + 3 + 4) = 37. Notice that on the 2nd Monday, Hercy only puts in $2.
// Example 3:

// Input: n = 20
// Output: 96
// Explanation: After the 20th day, the total is (1 + 2 + 3 + 4 + 5 + 6 + 7) + (2 + 3 + 4 + 5 + 6 + 7 + 8) + (3 + 4 + 5 + 6 + 7 + 8) = 96.
 

// Constraints:

// 1 <= n <= 1000



// 🚀 Approach
// 1. O(n) Solution
//     Simulate the saving process week by week.
//     Start with monday = 1 and iterate while n > 0.
//     For each week, add monday + day for up to 7 days.
//     After each week, decrement n by 7 and increment monday.
// 2. O(1) Solution
// Use arithmetic progression to compute the total for complete weeks:
//     Each week contributes a sum starting from monday = 1 and increasing.
//     First week sum is 28, second is 35, third is 42, etc.
//     Use AP formula: money = k * (f + l) / 2, where k = n / 7, f = 28, l = 28 + (k - 1) * 7.
// Handle the remaining days (n % 7) separately:
//     Start from monday = 1 + k and add monday + day for each leftover day.









// O(n) Solution...
class Solution {
    public int totalMoney(int n) {
        int money = 0;
        int monday = 1;

        while(n > 0) {
            for (int day = 0; day < Math.min(n , 7); day++) {
                money += monday + day;
            }
            n -= 7;
            monday++;
        }
        return money;
    }
}

// O(1) Solution...
class Solution {
    public int totalMoney(int n) {
        int k = n / 7;
        int f = 28;
        int l = 28 + (k - 1) * 7;
        int money = k * (f + l) / 2;

        int monday = 1 + k;
        int finalWeekMoney = 0;
        for (int day = 0; day < n % 7; day++) {
            finalWeekMoney += monday + day;
        }
        return money + finalWeekMoney;
    }
}
