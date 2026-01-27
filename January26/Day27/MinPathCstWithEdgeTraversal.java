// LEETCODE 3650. Minimum Cost Path with Edge Reversals

// You are given a directed, weighted graph with n nodes labeled from 0 to n - 1, and an array edges where edges[i] = [ui, vi, wi] represents a directed edge from node ui to node vi with cost wi.

// Each node ui has a switch that can be used at most once: when you arrive at ui and have not yet used its switch, you may activate it on one of its incoming edges vi → ui reverse that edge to ui → vi and immediately traverse it.

// The reversal is only valid for that single move, and using a reversed edge costs 2 * wi.

// Return the minimum total cost to travel from node 0 to node n - 1. If it is not possible, return -1.

 

// Example 1:

// Input: n = 4, edges = [[0,1,3],[3,1,1],[2,3,4],[0,2,2]]

// Output: 5

// Explanation:



// Use the path 0 → 1 (cost 3).
// At node 1 reverse the original edge 3 → 1 into 1 → 3 and traverse it at cost 2 * 1 = 2.
// Total cost is 3 + 2 = 5.
// Example 2:

// Input: n = 4, edges = [[0,2,1],[2,1,1],[1,3,1],[2,3,3]]

// Output: 3

// Explanation:

// No reversal is needed. Take the path 0 → 2 (cost 1), then 2 → 1 (cost 1), then 1 → 3 (cost 1).
// Total cost is 1 + 1 + 1 = 3.
 

// Constraints:

// 2 <= n <= 5 * 104
// 1 <= edges.length <= 105
// edges[i] = [ui, vi, wi]
// 0 <= ui, vi <= n - 1
// 1 <= wi <= 1000


// 🚀 Approach
// Construct an adjacency list where each edge (u, v, w) contributes:
//     u → v with cost w
//     v → u with cost 2w
// Use Dijkstra’s algorithm:
//     Maintain a priority queue storing (distance, node).
//     Keep a res array to track the minimum distance to each node.
//     Start from node 0 with distance 0.
//     At each step, pop the node with the smallest distance, and relax its neighbors:
//         If d + weight < res[adjNode], update and push into the queue.
// Stop early if we reach node n - 1, since Dijkstra guarantees the shortest path at that point.
// If node n - 1 is unreachable, return -1.

// 🕛 Complexity
// E = number of edges
// V = number of vertices

// Time complexity: O(ElogV)
// Space complexity: O(V + E)









class Solution {

    static class Pair {
        int node;
        int dist;

        Pair(int node, int dist) {
            this.node = node;
            this.dist = dist;
        }
    }

    public int minCost(int n, int[][] edges) {

        Map<Integer, List<Pair>> adj = new HashMap<>();

        for (int[] edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];

            adj.computeIfAbsent(u, k -> new ArrayList<>()).add(new Pair(v, wt));
            adj.computeIfAbsent(v, k -> new ArrayList<>()).add(new Pair(u, 2 * wt)); 
        }

        int[] dist = new int[n];
        Arrays.fill(dist, Integer.MAX_VALUE);
        dist[0] = 0;

        PriorityQueue<Pair> pq = new PriorityQueue<>((a, b) -> a.dist - b.dist);
        pq.offer(new Pair(0, 0));

        while (!pq.isEmpty()) {
            Pair cur = pq.poll();
            int node = cur.node;
            int d = cur.dist;

            if (d > dist[node]) continue;

            if (node == n - 1) return d;

            if (!adj.containsKey(node)) continue;

            for (Pair nei : adj.get(node)) {
                int nextNode = nei.node;
                int weight = nei.dist;

                if (d + weight < dist[nextNode]) {
                    dist[nextNode] = d + weight;
                    pq.offer(new Pair(nextNode, dist[nextNode]));
                }
            }
        }

        return -1;
    }
}