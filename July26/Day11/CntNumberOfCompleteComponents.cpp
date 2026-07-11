// LEETCODE 2685. Count the Number of Complete Components

// Let n be the number of vertices and m be the number of edges in the given graph.

// Time complexity: O(n + m * ɑ(n))
// Space complexity: O(n)



class DSU {
public:
    vector<int> parent;
    vector<int> size;

    DSU(int n) : parent(n , -1) , size(n , 1) {}

    int find(int node) {
        if (parent[node] == -1) {
            return node;
        }

        return parent[node] = find(parent[node]);
    }

    void unionSet(int x , int y) {
        int pX = find(x);
        int pY = find(y);

        if (pX == pY) return;

        if (size[pX] >= size[pY]) {
            parent[pY] = pX;
            size[pX] += size[pY];
        }
        else {
            parent[pX] = pY;
            size[pY] += size[pX];
        }
    }
};

class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        DSU dsu(n);
        unordered_map<int , int> edgeCnt;

        for (const auto& e : edges) {
            dsu.unionSet(e[0] , e[1]);
        }

        for (const auto& e : edges) {
            int root = dsu.find(e[0]);
            edgeCnt[root]++;
        }

        int completeCnt = 0;
        for (int v = 0; v < n; v++) {
            if (dsu.find(v) == v) {
                int nodeCnt = dsu.size[v];

                int expectedEdges = (nodeCnt * (nodeCnt - 1)) / 2;
                if (edgeCnt[v] == expectedEdges) {
                    completeCnt++;
                }
            }
        }

        return completeCnt;
    }
};