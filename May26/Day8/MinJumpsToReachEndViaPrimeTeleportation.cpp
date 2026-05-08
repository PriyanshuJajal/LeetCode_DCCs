// LEETCODE 3629. Minimum Jumps to Reach End via Prime Teleportation

// You are given an integer array nums of length n.

// You start at index 0, and your goal is to reach index n - 1.

// From any index i, you may perform one of the following operations:

// Adjacent Step: Jump to index i + 1 or i - 1, if the index is within bounds.
// Prime Teleportation: If nums[i] is a prime number p, you may instantly jump to any index j != i such that nums[j] % p == 0.
// Return the minimum number of jumps required to reach index n - 1.

 

// Example 1:

// Input: nums = [1,2,4,6]

// Output: 2

// Explanation:

// One optimal sequence of jumps is:

// Start at index i = 0. Take an adjacent step to index 1.
// At index i = 1, nums[1] = 2 is a prime number. Therefore, we teleport to index i = 3 as nums[3] = 6 is divisible by 2.
// Thus, the answer is 2.

// Example 2:

// Input: nums = [2,3,4,7,9]

// Output: 2

// Explanation:

// One optimal sequence of jumps is:

// Start at index i = 0. Take an adjacent step to index i = 1.
// At index i = 1, nums[1] = 3 is a prime number. Therefore, we teleport to index i = 4 since nums[4] = 9 is divisible by 3.
// Thus, the answer is 2.

// Example 3:

// Input: nums = [4,6,5,8]

// Output: 3

// Explanation:

// Since no teleportation is possible, we move through 0 → 1 → 2 → 3. Thus, the answer is 3.
 

// Constraints:

// 1 <= n == nums.length <= 105
// 1 <= nums[i] <= 106


// Time Complexity: O(maxEL * log(log(maxEl)))
// Space Complexity:  O(maxEl + n)




class Solution {
public:
    vector<bool> isPrime;
    void sieve(int maxEl) {
        isPrime.resize(maxEl + 1 , true);
        isPrime[0] = false;
        isPrime[1] = false;

        for (int num = 2; num * num <= maxEl; num++) {
            if (isPrime[num]) {
                for (int mul = num * num; mul <= maxEl; mul += num) {
                    isPrime[mul] = false;
                }
            }
        }
    }

    int minJumps(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int , vector<int>> mp;
        int maxEl = 0;

        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
            maxEl = max(maxEl , nums[i]);
        }

        sieve(maxEl);

        queue<int> q;
        vector<bool> vis(n , false);

        q.push(0);
        vis[0] = true;

        unordered_set<int> seen;
        int jumps = 0;

        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                int i = q.front();
                q.pop();

                if (i == n - 1) {
                    return jumps;
                }

                if (i - 1 >= 0 && !vis[i - 1]) {
                    q.push(i - 1);
                    vis[i - 1] = true;
                } 

                if (i + 1 <= n - 1 && !vis[i + 1]) {
                    q.push(i + 1);
                    vis[i + 1] = true;
                }

                if (!isPrime[nums[i]] || seen.count(nums[i])) continue;

                for (int m = nums[i]; m <= maxEl; m += nums[i]) {
                    if (!mp.contains(m)) {
                        continue;
                    }

                    for (int &j : mp[m]) {
                        if (!vis[j]) {
                            q.push(j);
                            vis[j] = true;
                        }
                    }
                }

                seen.insert(nums[i]);
            }
            jumps++;
        }
        return jumps;
    }
};