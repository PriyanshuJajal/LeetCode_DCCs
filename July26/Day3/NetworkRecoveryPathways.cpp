// LEETCODE 3620. Network Recovery Pathways


// Let V be the number of nodes, E the number of edges, and U be the maximum edge weight.

// Time complexity: O((V + E) * logU)
// Space complexity: O(V + E)


class Solution {
public:
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n = online.size();
        vector<vector<pair<int , int>>> adj(n);
        vector<int> deg(n , 0);
        int l = INT_MAX;
        int r = 0;

        for (auto& e : edges) {
            int u = e[0];
            int v = e[1];
            int w = e[2];

            if (!online[u] || !online[v]) continue;

            adj[u].push_back({v , w});
            deg[v]++;

            l = min(l , w);
            r = max(r , w);
        }

        queue<int> q;
        for (int i = 1; i < n; i++) {
            if (!deg[i]) {
                q.push(i);
            }
        }

        while(!q.empty()) {
            int u = q.front();
            q.pop();

            for (auto& [v , _] : adj[u]) {
                deg[v]--;

                if (v && deg[v] == 0) {
                    q.push(v);
                }
            }
        }

        auto check = [&](int mid) -> bool {
            vector<long long> dp(n , LLONG_MAX / 2);
            vector<int> cdeg = deg;
            dp[0] = 0;

            queue<int> q;
            q.push(0);

            while(!q.empty()) {
                int u = q.front();
                q.pop();

                if (u == n - 1) {
                    return dp[u] <= k;
                }

                for (auto& [v , w] : adj[u]) {
                    if (w >= mid) {
                        dp[v] = min(dp[v] , dp[u] + w);
                    }

                    cdeg[v]--;
                    if (!cdeg[v]) {
                        q.push(v);
                    }
                }
            }
            return false;
        };

        if (!check(l)) {
            return -1;
        }

        while(l <= r) {
            int mid = l + (r - l) / 2;
            if (check(mid)) {
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }
        return r;

    }
};