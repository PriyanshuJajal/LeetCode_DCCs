// LEETCODE 1331. Rank Transform of an Array

// Let n be the size of arr.

// Time Complexity: O(nlogn)
// Space Complexity: O(n)



class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        unordered_map<int , int> mp;
        set<int> nums(begin(arr) , end(arr));
        int rank = 1;

        for (auto num : nums) {
            mp[num] = rank;
            rank++;
        }

        for (int i = 0; i < arr.size(); i++) {
            arr[i] = mp[arr[i]];
        }
        return arr;
    }
};