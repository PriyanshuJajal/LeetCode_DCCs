// LEETCODE 2483. Minimum Penalty for a Shop

// You are given the customer visit log of a shop represented by a 0-indexed string customers consisting only of characters 'N' and 'Y':

// if the ith character is 'Y', it means that customers come at the ith hour
// whereas 'N' indicates that no customers come at the ith hour.
// If the shop closes at the jth hour (0 <= j <= n), the penalty is calculated as follows:

// For every hour when the shop is open and no customers come, the penalty increases by 1.
// For every hour when the shop is closed and customers come, the penalty increases by 1.
// Return the earliest hour at which the shop must be closed to incur a minimum penalty.

// Note that if a shop closes at the jth hour, it means the shop is closed at the hour j.

 

// Example 1:

// Input: customers = "YYNY"
// Output: 2
// Explanation: 
// - Closing the shop at the 0th hour incurs in 1+1+0+1 = 3 penalty.
// - Closing the shop at the 1st hour incurs in 0+1+0+1 = 2 penalty.
// - Closing the shop at the 2nd hour incurs in 0+0+0+1 = 1 penalty.
// - Closing the shop at the 3rd hour incurs in 0+0+1+1 = 2 penalty.
// - Closing the shop at the 4th hour incurs in 0+0+1+0 = 1 penalty.
// Closing the shop at 2nd or 4th hour gives a minimum penalty. Since 2 is earlier, the optimal closing time is 2.
// Example 2:

// Input: customers = "NNNNN"
// Output: 0
// Explanation: It is best to close the shop at the 0th hour as no customers arrive.
// Example 3:

// Input: customers = "YYYY"
// Output: 4
// Explanation: It is best to close the shop at the 4th hour as customers arrive at each hour.
 

// Constraints:

// 1 <= customers.length <= 105
// customers consists only of characters 'Y' and 'N'.





// 🚀 Approach
// We begin by calculating the penalty if the shop closes at hour 0, which is simply the total number of 'Y' customers in the string (since all of them would arrive after closing). This gives us a baseline penalty.
// Next, we iterate through the string hour by hour. At each step, we update the penalty based on the current character:
//     If the character is 'Y', the penalty decreases by 1 because that customer is now served before closing.
//     If the character is 'N', the penalty increases by 1 because we stayed open during an hour with no customers.
// While updating, we track the minimum penalty encountered and record the corresponding closing hour. After processing all hours, the recorded hour represents the optimal closing time with the least penalty.

// 🕛 Complexity
// Time complexity: O(n)
// Space complexity: O(1)










class Solution {
    public int bestClosingTime(String customers) {
        int n = customers.length();
        int penalty = 0;

        for (char cust : customers.toCharArray()) {
            if (cust == 'Y') penalty++;
        }

        int minPenalty = penalty;
        int bestHr = 0;

        for (int i = 0; i < n; i++) {
            if (customers.charAt(i) == 'Y') penalty--; 
            else penalty++;
            

            if (penalty < minPenalty) {
                minPenalty = penalty;
                bestHr = i + 1; 
            }
        }
        return bestHr;
    }
}