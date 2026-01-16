// LEETCODE 2975. Maximum Square Area by Removing Fences From a Field

// There is a large (m - 1) x (n - 1) rectangular field with corners at (1, 1) and (m, n) containing some horizontal and vertical fences given in arrays hFences and vFences respectively.

// Horizontal fences are from the coordinates (hFences[i], 1) to (hFences[i], n) and vertical fences are from the coordinates (1, vFences[i]) to (m, vFences[i]).

// Return the maximum area of a square field that can be formed by removing some fences (possibly none) or -1 if it is impossible to make a square field.

// Since the answer may be large, return it modulo 109 + 7.

// Note: The field is surrounded by two horizontal fences from the coordinates (1, 1) to (1, n) and (m, 1) to (m, n) and two vertical fences from the coordinates (1, 1) to (m, 1) and (1, n) to (m, n). These fences cannot be removed.

 

// Example 1:



// Input: m = 4, n = 3, hFences = [2,3], vFences = [2]
// Output: 4
// Explanation: Removing the horizontal fence at 2 and the vertical fence at 2 will give a square field of area 4.
// Example 2:



// Input: m = 6, n = 7, hFences = [2], vFences = [4]
// Output: -1
// Explanation: It can be proved that there is no way to create a square field by removing fences.
 

// Constraints:

// 3 <= m, n <= 109
// 1 <= hFences.length, vFences.length <= 600
// 1 < hFences[i] < m
// 1 < vFences[i] < n
// hFences and vFences are unique.



// 🚀 Approach
// Add boundaries: Include the edges of the field (1 and m for horizontal, 1 and n for vertical) to ensure we consider the full area.
// Sort fences: Sorting helps us compute consecutive differences easily.
// Compute horizontal gaps: For every pair of horizontal fences, calculate the distance and store it in a set (hGaps).
// Check vertical gaps: For every pair of vertical fences, calculate the distance. If this distance exists in hGaps, it means we can form a square of that side length.
// Track maximum side: Keep updating the maximum valid square side length.
// Return result: If no square can be formed, return -1. Otherwise, return the square of the maximum side length modulo 1e9 + 7.

// 🕛 Complexity
// Time complexity: O(h² + v²)
// Space complexity: O(h²)









import java.util.*;

class Solution {
    private static final int MOD = 1_000_000_007;

    public int maximizeSquareArea(int m, int n, List<Integer> hFences, List<Integer> vFences) {
        hFences.add(1);
        hFences.add(m);
        vFences.add(1);
        vFences.add(n);

        Collections.sort(hFences);
        Collections.sort(vFences);

        Set<Integer> hGaps = new HashSet<>();
        for (int i = 0; i < hFences.size(); i++) {
            for (int j = i + 1; j < hFences.size(); j++) {
                hGaps.add(hFences.get(j) - hFences.get(i));
            }
        }

        long maxSide = -1;
        for (int i = 0; i < vFences.size(); i++) {
            for (int j = i + 1; j < vFences.size(); j++) {
                int currGap = vFences.get(j) - vFences.get(i);
                if (hGaps.contains(currGap)) {
                    maxSide = Math.max(maxSide, currGap);
                }
            }
        }

        if (maxSide == -1) return -1;
        return (int)((maxSide * maxSide) % MOD);
    }
}