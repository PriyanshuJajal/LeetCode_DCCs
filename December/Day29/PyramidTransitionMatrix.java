// LEETCODE 756. Pyramid Transition Matrix


// You are stacking blocks to form a pyramid. Each block has a color, which is represented by a single letter. Each row of blocks contains one less block than the row beneath it and is centered on top.

// To make the pyramid aesthetically pleasing, there are only specific triangular patterns that are allowed. A triangular pattern consists of a single block stacked on top of two blocks. The patterns are given as a list of three-letter strings allowed, where the first two characters of a pattern represent the left and right bottom blocks respectively, and the third character is the top block.

// For example, "ABC" represents a triangular pattern with a 'C' block stacked on top of an 'A' (left) and 'B' (right) block. Note that this is different from "BAC" where 'B' is on the left bottom and 'A' is on the right bottom.
// You start with a bottom row of blocks bottom, given as a single string, that you must use as the base of the pyramid.

// Given bottom and allowed, return true if you can build the pyramid all the way to the top such that every triangular pattern in the pyramid is in allowed, or false otherwise.

 

// Example 1:


// Input: bottom = "BCD", allowed = ["BCC","CDE","CEA","FFF"]
// Output: true
// Explanation: The allowed triangular patterns are shown on the right.
// Starting from the bottom (level 3), we can build "CE" on level 2 and then build "A" on level 1.
// There are three triangular patterns in the pyramid, which are "BCC", "CDE", and "CEA". All are allowed.
// Example 2:


// Input: bottom = "AAAA", allowed = ["AAB","AAC","BCD","BBE","DEF"]
// Output: false
// Explanation: The allowed triangular patterns are shown on the right.
// Starting from the bottom (level 4), there are multiple ways to build level 3, but trying all the possibilites, you will get always stuck before building level 1.
 

// Constraints:

// 2 <= bottom.length <= 6
// 0 <= allowed.length <= 216
// allowed[i].length == 3
// The letters in all input strings are from the set {'A', 'B', 'C', 'D', 'E', 'F'}.
// All the values of allowed are unique.



// 🚀 Approach
// Preprocessing allowed triples
//     Store allowed transitions in a 2D adjacency matrix adj[7][7] (since only 7 letters A–G are valid).
//     Each entry adj[u][v] is a bitmask representing all possible top blocks that can sit above (u, v).
// Recursive construction (solve)
//     Base case: if the current row length is 1, we’ve successfully built the pyramid.
//     Otherwise, generate all possible next rows using buildRows.
// Row generation (buildRows)
//     For each pair of adjacent characters (curr[idx] , curr[idx + 1]), look up allowed top blocks in adj.
//     Recursively build all possible next rows by appending valid characters.
// Memoization
//     Use unordered_map<string , bool> to cache results for each row string to avoid recomputation.
// Final check
//     Start with the given bottom row and recursively attempt to build upwards.
//     Return true if any path leads to a single block pyramid.


// 🕛 Complexity
// Time complexity: O(7ⁿ)
// Space complexity: O(7ⁿ)










import java.util.*;

class Solution {
    int[][] adj = new int[7][7];
    Map<String, Boolean> memo = new HashMap<>();

    void buildRows(String curr, int idx, StringBuilder t, List<String> nxtRows) {
        if (idx == curr.length() - 1) {
            nxtRows.add(t.toString());
            return;
        }

        int u = curr.charAt(idx) - 'A';
        int v = curr.charAt(idx + 1) - 'A';
        int allowedMask = adj[u][v];

        if (allowedMask == 0) return;

        for (int i = 0; i < 7; i++) {
            if ((allowedMask & (1 << i)) != 0) {
                t.append((char)('A' + i));
                buildRows(curr, idx + 1, t, nxtRows);
                t.deleteCharAt(t.length() - 1); // backtrack
            }
        }
    }

    boolean solve(String curr) {
        if (curr.length() == 1) return true;
        if (memo.containsKey(curr)) return memo.get(curr);

        List<String> nxtRows = new ArrayList<>();
        StringBuilder t = new StringBuilder();

        buildRows(curr, 0, t, nxtRows);

        for (String nxtRow : nxtRows) {
            if (solve(nxtRow)) {
                memo.put(curr, true);
                return true;
            }
        }
        memo.put(curr, false);
        return false;
    }

    public boolean pyramidTransition(String bottom, List<String> allowed) {
        for (int i = 0; i < 7; i++) {
            Arrays.fill(adj[i], 0);
        }
        memo.clear();

        for (String s : allowed) {
            int u = s.charAt(0) - 'A';
            int v = s.charAt(1) - 'A';
            int top = s.charAt(2) - 'A';

            adj[u][v] |= (1 << top);
        }
        return solve(bottom);
    }
}