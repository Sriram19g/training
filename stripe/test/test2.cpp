#include <bits/stdc++.h>
using namespace std;

int dfs(int node, vector<int>& time, unordered_map<int, vector<int>>& graph, vector<int>& dist) {
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

int main() {
    vector<vector<int>> r1 = {{1, 5}, {2, 5}, {3, 5}, {3, 4}, {4, 5}};
    vector<int> t1 = {1, 2, 3, 4, 5};
    int n1 = t1.size();
    int ans1 = minimumTime(n1, r1, t1);
    cout << ans1 << endl;
}
