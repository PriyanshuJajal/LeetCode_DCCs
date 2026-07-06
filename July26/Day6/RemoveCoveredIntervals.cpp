// LEETCODE 1288. Remove Covered Intervals

// Time Complexity: O(nlogn)
// Space Complexity: O(1)



class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(begin(intervals) , end(intervals) , [](auto& a , auto& b) {
            if (a[0] == b[0]) {
                return a[1] > b[1];
            }
            
            return a[0] < b[0];
        });

        int cnt = 0;
        int lastEnd = 0;

        for (auto& it : intervals) {
            if (it[1] > lastEnd) {
                cnt++;
                lastEnd = it[1];
            }
        }
        return cnt;
    }
};