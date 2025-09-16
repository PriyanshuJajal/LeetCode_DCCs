// LEETCODE 2197. Replace Non-Coprime Numbers in Array

// You are given an array of integers nums. Perform the following steps:

// Find any two adjacent numbers in nums that are non-coprime.
// If no such numbers are found, stop the process.
// Otherwise, delete the two numbers and replace them with their LCM (Least Common Multiple).
// Repeat this process as long as you keep finding two adjacent non-coprime numbers.
// Return the final modified array. It can be shown that replacing adjacent non-coprime numbers in any arbitrary order will lead to the same result.

// The test cases are generated such that the values in the final array are less than or equal to 108.

// Two values x and y are non-coprime if GCD(x, y) > 1 where GCD(x, y) is the Greatest Common Divisor of x and y.

 

// Example 1:

// Input: nums = [6,4,3,2,7,6,2]
// Output: [12,7,6]
// Explanation: 
// - (6, 4) are non-coprime with LCM(6, 4) = 12. Now, nums = [12,3,2,7,6,2].
// - (12, 3) are non-coprime with LCM(12, 3) = 12. Now, nums = [12,2,7,6,2].
// - (12, 2) are non-coprime with LCM(12, 2) = 12. Now, nums = [12,7,6,2].
// - (6, 2) are non-coprime with LCM(6, 2) = 6. Now, nums = [12,7,6].
// There are no more adjacent non-coprime numbers in nums.
// Thus, the final modified array is [12,7,6].
// Note that there are other ways to obtain the same resultant array.
// Example 2:

// Input: nums = [2,2,1,1,3,3,3]
// Output: [2,1,1,3]
// Explanation: 
// - (3, 3) are non-coprime with LCM(3, 3) = 3. Now, nums = [2,2,1,1,3,3].
// - (3, 3) are non-coprime with LCM(3, 3) = 3. Now, nums = [2,2,1,1,3].
// - (2, 2) are non-coprime with LCM(2, 2) = 2. Now, nums = [2,1,1,3].
// There are no more adjacent non-coprime numbers in nums.
// Thus, the final modified array is [2,1,1,3].
// Note that there are other ways to obtain the same resultant array.
 

// Constraints:

// 1 <= nums.length <= 105
// 1 <= nums[i] <= 105
// The test cases are generated such that the values in the final array are less than or equal to 108.



// 🚀 Approach
// Traverse the input array from left to right.
// For each number, check if it shares a common factor with the last element in the result list.
// If GCD > 1, pop the last element and replace both with their LCM.
// Repeat this until the current number is coprime with the last element or the result list is empty.
// Push the final merged value into the result list.
// Return the result list res.




class Solution {
    public int GCD(int x , int y) {
        while(y != 0) {
            int t = y;
            y = x % y;
            x = t;
        }
        return x;
    }

    public List<Integer> replaceNonCoprimes(int[] nums) {
        List<Long> ans = new ArrayList<>();
        for (int num : nums) {
            long currNum = num;

            while(!ans.isEmpty()) {
                long lastNum = ans.get(ans.size() - 1);
                int gcd = GCD((int)currNum , (int)lastNum);

                if (gcd > 1) {
                    ans.remove(ans.size() - 1);
                    currNum = (currNum * lastNum) / gcd;
                }
                else break;
            }
            ans.add(currNum);
        }

        List<Integer> res = new ArrayList<>();
        for (long val : ans) res.add((int)val);
        
        return res;
    }
}