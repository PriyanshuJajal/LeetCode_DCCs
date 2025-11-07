// LEETCODE 2528. Maximize the Minimum Powered City

// You are given a 0-indexed integer array stations of length n, where stations[i] represents the number of power stations in the ith city.

// Each power station can provide power to every city in a fixed range. In other words, if the range is denoted by r, then a power station at city i can provide power to all cities j such that |i - j| <= r and 0 <= i, j <= n - 1.

// Note that |x| denotes absolute value. For example, |7 - 5| = 2 and |3 - 10| = 7.
// The power of a city is the total number of power stations it is being provided power from.

// The government has sanctioned building k more power stations, each of which can be built in any city, and have the same range as the pre-existing ones.

// Given the two integers r and k, return the maximum possible minimum power of a city, if the additional power stations are built optimally.

// Note that you can build the k power stations in multiple cities.

 

// Example 1:

// Input: stations = [1,2,4,5,0], r = 1, k = 2
// Output: 5
// Explanation: 
// One of the optimal ways is to install both the power stations at city 1. 
// So stations will become [1,4,4,5,0].
// - City 0 is provided by 1 + 4 = 5 power stations.
// - City 1 is provided by 1 + 4 + 4 = 9 power stations.
// - City 2 is provided by 4 + 4 + 5 = 13 power stations.
// - City 3 is provided by 5 + 4 = 9 power stations.
// - City 4 is provided by 5 + 0 = 5 power stations.
// So the minimum power of a city is 5.
// Since it is not possible to obtain a larger power, we return 5.
// Example 2:

// Input: stations = [4,4,4,4], r = 0, k = 3
// Output: 4
// Explanation: 
// It can be proved that we cannot make the minimum power of a city greater than 4.
 

// Constraints:

// n == stations.length
// 1 <= n <= 105
// 0 <= stations[i] <= 105
// 0 <= r <= n - 1
// 0 <= k <= 109





// 🚀 Approach
// Binary Search over the answer:
//     We search for the maximum value of targetPow such that all stations can reach at least this power level using at most k additional units.
//     The search range is from 0 to sum(stations) + k.
// Greedy Check (isEnough):
//     For each station, compute its current power using a sliding window of size 2r + 1.
//     If the power is less than targetPow, we simulate adding power at the farthest possible index (i + r) to cover the current station.
//     Track added power separately to avoid modifying the original array.
//     If at any point the required additions exceed k, return false.
// Sliding Window Optimization:
//     Maintain a running sum pow of the current window.
//     Update it incrementally as the window slides forward, subtracting the leftmost element and adding the new rightmost one.


// 🕛 Complexity

// Time complexity: O(n * log(sum + k))
//     Binary search runs in O(log(sum + k))
//     Each isEnough call runs in O(n)

// Space complexity: O(n)











class Solution {
    public boolean isEnough(List<Integer> stations , int r , long targetPow , long addedSt) {
        int n = stations.size();
        long pow = 0;
        for (int i = 0; i < Math.min(r, n); i++) {
            pow += stations.get(i);
        }

        long[] addPower = new long[n];

        for (int i = 0; i < n; i++) {
            if (i + r < n) pow += stations.get(i + r);

            if (pow < targetPow) {
                long needed = targetPow - pow;
                if (needed > addedSt) return false;

                int idx = Math.min(n - 1, i + r);
                addPower[idx] += needed;
                pow = targetPow;
                addedSt -= needed;
            }
            if (i - r >= 0) {
                pow -= stations.get(i - r) + addPower[i - r];
            }
        }
        return true;
    }

    public long maxPower(int[] stations, int r, int k) {
        List<Integer> stationList = new ArrayList<>();
        for (int s : stations) stationList.add(s);

        long l = 0;
        long h = Arrays.stream(stations).asLongStream().sum() + k;
        long res = 0;

        while (l <= h) {
            long mid = l + (h - l) / 2;
            if (isEnough(stationList , r , mid , k)) {
                res = mid;
                l = mid + 1;
            } else {
                h = mid - 1;
            }
        }
        return res;
    }
}
