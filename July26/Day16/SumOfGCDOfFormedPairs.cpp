// LEETCODE 3867. Sum of GCD of Formed Pairs

// Time Complexity: O(nlogn + nlogM) , M = max of nums
// Space Complexity: O(n)



class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefGCD(n);
        int mx = nums[0];

        for (int i = 0; i < n; i++) {
            mx = max(mx , nums[i]);
            prefGCD[i] = gcd(nums[i] , mx);
        }

        sort(begin(prefGCD) , end(prefGCD));

        long long sum = 0;
        int i = 0 , j = n - 1;
        while(i < j) {
            sum += (gcd(prefGCD[i] , prefGCD[j]));
            i++;
            j--;
        }

        return sum;
    }
};