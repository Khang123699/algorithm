class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, 0);
        auto dfs = [&](auto& self, int node, int c) -> bool {
            color[node] = c;
            for (int neighbor : graph[node]) {
                if (color[neighbor] == c) return false;
                if (color[neighbor] == 0 && !self(self, neighbor, -c)) return false;
            }
            return true;
        };
        for (int i = 0; i < n; i++) {
            if (color[i] == 0 && !dfs(dfs, i, 1)) {
                return false;
            }
        }
        return true;
    }
};