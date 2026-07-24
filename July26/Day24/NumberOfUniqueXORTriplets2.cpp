// LEETCODE 3514. Number of Unique XOR Triplets II

// M = 2048 is the maximum possible XOR value

// Time complexity: O(n * M)
// Space complexity: O(M)



class Solution {
public:
    const int MAX = 2048;
    int uniqueXorTriplets(vector<int>& nums) {
        if (nums.size() == 1) return 1;
        
        vector<bool> one(MAX , false);
        vector<bool> two(MAX , false);
        vector<bool> three(MAX , false);

        for (int val : nums) {
            for (int x = 0; x < MAX; x++) {
                if (one[x]) {
                    two[x ^ val] = true;
                }
            }
            one[val] = true;
        }

        for (int val : nums) {
            for (int x = 0; x < MAX; x++) {
                if (two[x]) {
                    three[x ^ val] = true;
                }
            }
        }

        int triplets = 0;
        for (bool exists: three) {
            triplets += exists;
        }

        return triplets;
    }
};