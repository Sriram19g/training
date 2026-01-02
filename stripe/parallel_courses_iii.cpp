#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        unordered_map<int, vector<int>> graph;
        vector<int> dist(n, -1);
        for (auto& i : relations) {
            int x = i[0] - 1;
            int y = i[1] - 1;
            graph[x].push_back(y);
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans = max(ans, dfs(i, time, graph, dist));
        }
        return ans;
    }
    int dfs(int node, vector<int>& time, unordered_map<int, vector<int>>& graph,
            vector<int>& dist) {
        if (dist[node] != -1) {
            return dist[node];
        }
        if (graph[node].size() == 0) {
            return time[node];
        }
        int ans = 0;
        for (int neigh : graph[node]) {
            ans = max(ans, dfs(neigh, time, graph, dist));
        }
        dist[node] = time[node] + ans;
        return dist[node];
    }
};

int main() {
    Solution soln;
    vector<vector<int>> relations = {{1, 5}, {2, 5}, {3, 5}, {3, 4}, {4, 5}};
    vector<int> tim = {1, 2, 3, 4, 5};
    int n = tim.size();
    int ans = soln.minimumTime(n, relations, tim);
    cout << ans << endl;
    return 0;
}
