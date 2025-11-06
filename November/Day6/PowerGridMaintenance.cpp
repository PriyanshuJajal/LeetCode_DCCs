// LEETCODE 3607. Power Grid Maintenance

// You are given an integer c representing c power stations, each with a unique identifier id from 1 to c (1‑based indexing).

// These stations are interconnected via n bidirectional cables, represented by a 2D array connections, where each element connections[i] = [ui, vi] indicates a connection between station ui and station vi. Stations that are directly or indirectly connected form a power grid.

// Initially, all stations are online (operational).

// You are also given a 2D array queries, where each query is one of the following two types:

// [1, x]: A maintenance check is requested for station x. If station x is online, it resolves the check by itself. If station x is offline, the check is resolved by the operational station with the smallest id in the same power grid as x. If no operational station exists in that grid, return -1.

// [2, x]: Station x goes offline (i.e., it becomes non-operational).

// Return an array of integers representing the results of each query of type [1, x] in the order they appear.

// Note: The power grid preserves its structure; an offline (non‑operational) node remains part of its grid and taking it offline does not alter connectivity.

 

// Example 1:

// Input: c = 5, connections = [[1,2],[2,3],[3,4],[4,5]], queries = [[1,3],[2,1],[1,1],[2,2],[1,2]]

// Output: [3,2,3]

// Explanation:



// Initially, all stations {1, 2, 3, 4, 5} are online and form a single power grid.
// Query [1,3]: Station 3 is online, so the maintenance check is resolved by station 3.
// Query [2,1]: Station 1 goes offline. The remaining online stations are {2, 3, 4, 5}.
// Query [1,1]: Station 1 is offline, so the check is resolved by the operational station with the smallest id among {2, 3, 4, 5}, which is station 2.
// Query [2,2]: Station 2 goes offline. The remaining online stations are {3, 4, 5}.
// Query [1,2]: Station 2 is offline, so the check is resolved by the operational station with the smallest id among {3, 4, 5}, which is station 3.
// Example 2:

// Input: c = 3, connections = [], queries = [[1,1],[2,1],[1,1]]

// Output: [1,-1]

// Explanation:

// There are no connections, so each station is its own isolated grid.
// Query [1,1]: Station 1 is online in its isolated grid, so the maintenance check is resolved by station 1.
// Query [2,1]: Station 1 goes offline.
// Query [1,1]: Station 1 is offline and there are no other stations in its grid, so the result is -1.
 

// Constraints:

// 1 <= c <= 105
// 0 <= n == connections.length <= min(105, c * (c - 1) / 2)
// connections[i].length == 2
// 1 <= ui, vi <= c
// ui != vi
// 1 <= queries.length <= 2 * 105
// queries[i].length == 2
// queries[i][0] is either 1 or 2.
// 1 <= queries[i][1] <= c




// 🚀 Approach
// We use a DSU to maintain connected components and augment it with a Set per component to track online nodes in sorted order. Each node starts online and in its own component.
//     Union merges components and their online node sets.
//     goOffline(x) marks node x offline and removes it from its component’s online set.
//     getMinOnline(x) returns the smallest online node in the component containing x, or -1 if none are online.
// The DSU uses path compression and union by size for efficiency. The Set ensures fast retrieval of the minimum online node.


// 🕛 Complexity
// Time complexity: O(qlogn)
// q: processing queries
// find, unionSet: amortized O(α(n)) per operation (inverse Ackermann)
// goOffline: O(log n)
// getMinOnline: O(1) for isOnline[x], O(log n) for fetching min Online Node

// Space complexity: O(n)
// DSU arrays: O(n)
// Online node sets: worst-case O(n²) if all nodes stay in separate sets, but typically
// O(n)










struct DSU {
    vector<int> parent;
    vector<int> size;
    vector<set<int>> onlineNodes;

    DSU(int n) {
        parent.resize(n + 1);
        size.resize(n + 1 , 1);
        onlineNodes.resize(n + 1);

        for (int i = 1; i <= n; i++) {
            parent[i] = i;
            onlineNodes[i].insert(i);
        }
    }

    int find(int i) {
        if (parent[i] == i) return i;
        return parent[i] = find(parent[i]);
    }

    void unionSet(int i , int j) {
        int iParent = find(i);
        int jParent = find(j);

        if (iParent == jParent) return;
        if (size[iParent] < size[jParent]) swap(iParent , jParent);

        parent[jParent] = iParent;
        size[iParent] += size[jParent];

        if (!onlineNodes[iParent].empty()) {
            onlineNodes[iParent].insert(
                onlineNodes[jParent].begin() , 
                onlineNodes[jParent].end()
            );

            onlineNodes[jParent].clear();
        }
    }

    void goOffline(int x , vector<bool>& isOnline) {
        if (!isOnline[x]) return;
        isOnline[x] = false;

        int root = find(x);
        onlineNodes[root].erase(x);
    }

    int getMinOnline(int x , const vector<bool>& isOnline) {
        if (isOnline[x]) return x;

        int root = find(x);
        if (onlineNodes[root].empty()) return -1;
        else return *onlineNodes[root].begin();
    }
};

class Solution {
public:
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        DSU dsu(c);
        vector<bool> isOnline(c + 1 , true);

        for (const auto& conn : connections) {
            dsu.unionSet(conn[0] , conn[1]);
        }

        vector<int> res;

        for (const auto& q : queries) {
            int type = q[0];
            int x = q[1];

            if (type == 2) dsu.goOffline(x , isOnline);
            else res.push_back(dsu.getMinOnline(x , isOnline));
        }
        return res;
    }
};
