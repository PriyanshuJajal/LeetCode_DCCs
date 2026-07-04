// LEETCODE 2492. Minimum Score of a Path Between Two Cities

 
// n = number of nodes & 𝑚 = number of roads

// Time Complexity: O(n + m)
// Space Complexity: O(n + m)


class Solution {
public:
    void dfs(int u , unordered_map<int , vector<pair<int , int>>>& adj , vector<bool>& vis , int& score) {
        vis[u] = true;
        
        for (auto& p : adj[u]) {
            int v = p.first;
            int d = p.second;

            score = min(score , d);

            if (!vis[v]) {
                dfs(v , adj , vis , score);
            }
        }
    }

    int minScore(int n, vector<vector<int>>& roads) {
        unordered_map<int , vector<pair<int , int>>> adj;

        for (auto& vec : roads) {
            int u = vec[0];
            int v = vec[1];
            int d = vec[2];

            adj[u].push_back({v , d});
            adj[v].push_back({u , d});
        }

        vector<bool> vis(n , false);
        int score = INT_MAX;

        dfs(1 , adj , vis , score);

        return score;
    }
};