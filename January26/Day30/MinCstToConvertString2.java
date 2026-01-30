// LEETCODE 2977. Minimum Cost to Convert String II

// You are given two 0-indexed strings source and target, both of length n and consisting of lowercase English characters. You are also given two 0-indexed string arrays original and changed, and an integer array cost, where cost[i] represents the cost of converting the string original[i] to the string changed[i].

// You start with the string source. In one operation, you can pick a substring x from the string, and change it to y at a cost of z if there exists any index j such that cost[j] == z, original[j] == x, and changed[j] == y. You are allowed to do any number of operations, but any pair of operations must satisfy either of these two conditions:

// The substrings picked in the operations are source[a..b] and source[c..d] with either b < c or d < a. In other words, the indices picked in both operations are disjoint.
// The substrings picked in the operations are source[a..b] and source[c..d] with a == c and b == d. In other words, the indices picked in both operations are identical.
// Return the minimum cost to convert the string source to the string target using any number of operations. If it is impossible to convert source to target, return -1.

// Note that there may exist indices i, j such that original[j] == original[i] and changed[j] == changed[i].

 

// Example 1:

// Input: source = "abcd", target = "acbe", original = ["a","b","c","c","e","d"], changed = ["b","c","b","e","b","e"], cost = [2,5,5,1,2,20]
// Output: 28
// Explanation: To convert "abcd" to "acbe", do the following operations:
// - Change substring source[1..1] from "b" to "c" at a cost of 5.
// - Change substring source[2..2] from "c" to "e" at a cost of 1.
// - Change substring source[2..2] from "e" to "b" at a cost of 2.
// - Change substring source[3..3] from "d" to "e" at a cost of 20.
// The total cost incurred is 5 + 1 + 2 + 20 = 28. 
// It can be shown that this is the minimum possible cost.
// Example 2:

// Input: source = "abcdefgh", target = "acdeeghh", original = ["bcd","fgh","thh"], changed = ["cde","thh","ghh"], cost = [1,3,5]
// Output: 9
// Explanation: To convert "abcdefgh" to "acdeeghh", do the following operations:
// - Change substring source[1..3] from "bcd" to "cde" at a cost of 1.
// - Change substring source[5..7] from "fgh" to "thh" at a cost of 3. We can do this operation because indices [5,7] are disjoint with indices picked in the first operation.
// - Change substring source[5..7] from "thh" to "ghh" at a cost of 5. We can do this operation because indices [5,7] are disjoint with indices picked in the first operation, and identical with indices picked in the second operation.
// The total cost incurred is 1 + 3 + 5 = 9.
// It can be shown that this is the minimum possible cost.
// Example 3:

// Input: source = "abcdefgh", target = "addddddd", original = ["bcd","defgh"], changed = ["ddd","ddddd"], cost = [100,1578]
// Output: -1
// Explanation: It is impossible to convert "abcdefgh" to "addddddd".
// If you select substring source[1..3] as the first operation to change "abcdefgh" to "adddefgh", you cannot select substring source[3..7] as the second operation because it has a common index, 3, with the first operation.
// If you select substring source[3..7] as the first operation to change "abcdefgh" to "abcddddd", you cannot select substring source[1..3] as the second operation because it has a common index, 3, with the first operation.
 

// Constraints:

// 1 <= source.length == target.length <= 1000
// source, target consist only of lowercase English characters.
// 1 <= cost.length == original.length == changed.length <= 100
// 1 <= original[i].length == changed[i].length <= source.length
// original[i], changed[i] consist only of lowercase English characters.
// original[i] != changed[i]
// 1 <= cost[i] <= 106



// 🚀 Approach
// Graph Construction
//     Treat each unique substring (from original & changed) as a node.
//     Build edges between nodes with the given costs.
//     Use Floyd–Warshall to compute the minimum cost between all pairs of substrings (transitive closure of transformations).

// Dynamic Programming on the Source String
//     Define dp[i] as the minimum cost to transform the suffix starting at position i.
//     Base case: dp[n] = 0 (empty suffix costs nothing).
//     Transition:
//         If source[i] == target[i], then dp[i] = dp[i+1].
//         Otherwise, try all substrings s1 starting at i in source.
//             For each possible transformation s1 → s2 (same length), if s2 matches the corresponding substring in target, update:
//             dp[i] = min(dp[i] , cost(s1 → s2) + dp[i + len(s1)])

// The result is dp[0].
// If no valid transformation exists, return -1.


// 🕛 Complexity
// n = length of source

// Time complexity: O(V³ + n * V²)
// Space complexity: O(V² + n)









import java.util.*;

class Solution {
    public long minimumCost(String source, String target, 
                            List<String> original, 
                            List<String> changed, 
                            List<Integer> cost) {
        final long INF = Long.MAX_VALUE / 4;
        int n = source.length();
        int m = original.size();

        Map<String, Integer> id = new HashMap<>();
        List<String> nodes = new ArrayList<>();

        // Assign unique IDs to substrings
        java.util.function.Function<String, Integer> getId = s -> {
            if (!id.containsKey(s)) {
                id.put(s, nodes.size());
                nodes.add(s);
            }
            return id.get(s);
        };

        for (int i = 0; i < m; i++) {
            getId.apply(original.get(i));
            getId.apply(changed.get(i));
        }

        int cnt = nodes.size();
        long[][] dist = new long[cnt][cnt];
        for (int i = 0; i < cnt; i++) {
            Arrays.fill(dist[i], INF);
            dist[i][i] = 0;
        }

        for (int i = 0; i < m; i++) {
            int u = getId.apply(original.get(i));
            int v = getId.apply(changed.get(i));
            dist[u][v] = Math.min(dist[u][v], (long) cost.get(i));
        }

        // Floyd–Warshall for all-pairs shortest paths
        for (int k = 0; k < cnt; k++) {
            for (int i = 0; i < cnt; i++) {
                for (int j = 0; j < cnt; j++) {
                    if (dist[i][k] < INF && dist[k][j] < INF) {
                        dist[i][j] = Math.min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }

        long[] dp = new long[n + 1];
        Arrays.fill(dp, INF);
        dp[n] = 0;

        // DP from end to start
        for (int i = n - 1; i >= 0; i--) {
            if (source.charAt(i) == target.charAt(i)) {
                dp[i] = dp[i + 1];
            }

            for (int u = 0; u < cnt; u++) {
                String s1 = nodes.get(u);
                int len = s1.length();
                if (i + len > n) continue;

                if (!source.startsWith(s1, i)) continue;

                for (int v = 0; v < cnt; v++) {
                    if (dist[u][v] == INF) continue;

                    String s2 = nodes.get(v);
                    if (s2.length() != len) continue;

                    if (target.startsWith(s2, i) && dp[i + len] < INF) {
                        dp[i] = Math.min(dp[i], dist[u][v] + dp[i + len]);
                    }
                }
            }
        }

        return dp[0] >= INF ? -1 : dp[0];
    }
}