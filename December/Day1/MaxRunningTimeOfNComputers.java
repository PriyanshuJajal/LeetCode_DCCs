// LEETCODE 2141. Maximum Running Time of N Computers

// You have n computers. You are given the integer n and a 0-indexed integer array batteries where the ith battery can run a computer for batteries[i] minutes. You are interested in running all n computers simultaneously using the given batteries.

// Initially, you can insert at most one battery into each computer. After that and at any integer time moment, you can remove a battery from a computer and insert another battery any number of times. The inserted battery can be a totally new battery or a battery from another computer. You may assume that the removing and inserting processes take no time.

// Note that the batteries cannot be recharged.

// Return the maximum number of minutes you can run all the n computers simultaneously.

 

// Example 1:


// Input: n = 2, batteries = [3,3,3]
// Output: 4
// Explanation: 
// Initially, insert battery 0 into the first computer and battery 1 into the second computer.
// After two minutes, remove battery 1 from the second computer and insert battery 2 instead. Note that battery 1 can still run for one minute.
// At the end of the third minute, battery 0 is drained, and you need to remove it from the first computer and insert battery 1 instead.
// By the end of the fourth minute, battery 1 is also drained, and the first computer is no longer running.
// We can run the two computers simultaneously for at most 4 minutes, so we return 4.

// Example 2:


// Input: n = 2, batteries = [1,1,1,1]
// Output: 2
// Explanation: 
// Initially, insert battery 0 into the first computer and battery 2 into the second computer. 
// After one minute, battery 0 and battery 2 are drained so you need to remove them and insert battery 1 into the first computer and battery 3 into the second computer. 
// After another minute, battery 1 and battery 3 are also drained so the first and second computers are no longer running.
// We can run the two computers simultaneously for at most 2 minutes, so we return 2.
 

// Constraints:

// 1 <= n <= batteries.length <= 105
// 1 <= batteries[i] <= 109



// 🚀 Approach
// Binary Search Setup:
//     Compute the total sum of all battery capacities.
//     The maximum possible runtime per computer is sum / n.
//     The minimum possible runtime is the smallest battery capacity.
// Feasibility Check (possible function) :
//     For a candidate runtime midTime, calculate the total energy required: n * midTime.
//     Traverse each battery and subtract its contribution (at most midTime).
//     If the remaining target becomes ≤ 0, it means we can achieve this runtime.
// Binary Search Execution :
//     If midTime is feasible, move the lower bound up (l = mid + 1) and record the result.
//     Otherwise, reduce the upper bound (r = mid - 1).
//     Continue until bounds converge.
// The last feasible midTime is the maximum runtime achievable.


// 🕛 Complexity
// Time complexity: O(m * log(sum / n))
// m = length of batteries

// Space complexity: O(1)













class Solution {
    private boolean possible(int[] batteries , long midTime , int n) {
        long target = n * midTime;

        for (int b : batteries) {
            target -= Math.min((long) b , midTime);
            if (target <= 0) return true;
        }
        return target <= 0;
    }

    public long maxRunTime(int n , int[] batteries) {
        long l = Long.MAX_VALUE;
        long sum = 0;
        for (int b : batteries) {
            l = Math.min(l , b);
            sum += b;
        }

        long r = sum / n;
        long res = 0;
        while (l <= r) {
            long mid = l + (r - l) / 2;
            if (possible(batteries, mid, n)) {
                res = mid;
                l = mid + 1;
            }
            else  r = mid - 1;
        }
        return res;
    }
}
