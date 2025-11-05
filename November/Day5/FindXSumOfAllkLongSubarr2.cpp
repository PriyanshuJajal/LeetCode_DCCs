// LEETCODE 3321. Find X-Sum of All K-Long Subarrays II


// You are given an array nums of n integers and two integers k and x.

// The x-sum of an array is calculated by the following procedure:

// Count the occurrences of all elements in the array.
// Keep only the occurrences of the top x most frequent elements. If two elements have the same number of occurrences, the element with the bigger value is considered more frequent.
// Calculate the sum of the resulting array.
// Note that if an array has less than x distinct elements, its x-sum is the sum of the array.

// Return an integer array answer of length n - k + 1 where answer[i] is the x-sum of the subarray nums[i..i + k - 1].

 

// Example 1:

// Input: nums = [1,1,2,2,3,4,2,3], k = 6, x = 2

// Output: [6,10,12]

// Explanation:

// For subarray [1, 1, 2, 2, 3, 4], only elements 1 and 2 will be kept in the resulting array. Hence, answer[0] = 1 + 1 + 2 + 2.
// For subarray [1, 2, 2, 3, 4, 2], only elements 2 and 4 will be kept in the resulting array. Hence, answer[1] = 2 + 2 + 2 + 4. Note that 4 is kept in the array since it is bigger than 3 and 1 which occur the same number of times.
// For subarray [2, 2, 3, 4, 2, 3], only elements 2 and 3 are kept in the resulting array. Hence, answer[2] = 2 + 2 + 2 + 3 + 3.
// Example 2:

// Input: nums = [3,8,7,8,7,5], k = 2, x = 2

// Output: [11,15,15,15,12]

// Explanation:

// Since k == x, answer[i] is equal to the sum of the subarray nums[i..i + k - 1].

 

// Constraints:

// nums.length == n
// 1 <= n <= 105
// 1 <= nums[i] <= 109
// 1 <= x <= k <= nums.length




// 🚀 Approach
// Use a frequency map to track how many times each element appears in the current window.
// Maintain 2 multisets (C++) or 2 TreeSets (Java):
//     topX: top x contributors (sorted by frequency and value).
//     st: remaining contributors.
// Rebalance these sets after every update:
//     Ensure topX has exactly x elements.
//     Swap elements between topX and st if a better contributor is available.
// Slide the window:
//     Remove the outgoing element.
//     Add the incoming element.
// Rebalance and record the sum.


// 🕛 Complexity
// Time complexity: O(nlogk)
// Space complexity: O(k)









class Solution {
    using P = pair<long long , long long>;

    multiset<P> topX;
    multiset<P> st;
    unordered_map<int , int> mp;
    long long currXSum = 0;
    int xVal;

    void rebalance() {
        int sz = min(xVal , (int)mp.size());
        while(topX.size() < sz && !st.empty()) {
            P best = *st.rbegin();
            st.erase(prev(st.end()));

            topX.insert(best);
            currXSum += best.first * best.second;
        }

        while(topX.size() > sz) {
            P worst = *topX.begin();
            topX.erase(topX.begin());

            st.insert(worst);
            currXSum -= worst.first * worst.second;
        }

        while(!topX.empty() && !st.empty() && *topX.begin() < *st.rbegin()) {
            P worst = *topX.begin();
            P best = *st.rbegin();

            topX.erase(topX.begin());
            st.erase(prev(st.end()));

            topX.insert(best);
            st.insert(worst);

            currXSum -= worst.first * worst.second;
            currXSum += best.first * best.second;
        }
    }

    void updateEl(int el , int changeFreq) {
        long long oldFreq = mp[el];
        long long newFreq = oldFreq + changeFreq;

        P oldPair = {oldFreq , (long long)el};
        P newPair = {newFreq , (long long)el};

        if (oldFreq > 0) {
            auto it_top = topX.find(oldPair);
            if (it_top != topX.end()) {
                topX.erase(it_top);
                currXSum -= oldFreq * el;
            }
            else {
                auto it_st = st.find(oldPair);
                if (it_st != st.end()) {
                    st.erase(it_st);   
                }
            }
        }

        mp[el] = newFreq;
        if (newFreq > 0) st.insert(newPair);
        else mp.erase(el);

        rebalance();
    }

public:
    vector<long long> findXSum(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<long long> res;

        topX.clear();
        st.clear();
        mp.clear();
        currXSum = 0;
        this -> xVal = x;

        for (int i = 0; i < k; i++) {
            mp[nums[i]]++;
        }

        for (auto& it : mp) {
            st.insert({(long long)it.second , (long long)it.first});
        }

        rebalance();
        res.push_back(currXSum);

        for (int i = 0; i < n - k; i++) {
            int elOut = nums[i];
            int elIn = nums[i + k];

            updateEl(elOut , -1);
            updateEl(elIn , 1);

            res.push_back(currXSum);
        }
        return res;
    }
};