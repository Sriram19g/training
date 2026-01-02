#include <bits/stdc++.h>
using namespace std;

double dfs(char source, char dest, unordered_map<char, vector<pair<char, double>>>& graph,
           vector<bool>& visited) {
    if (source == dest)
        return 1.0;
    visited[source - 'a'] = true;
    for (auto& i : graph[source]) {
        char next = i.first;
        double weight = i.second;
        if (!visited[next - 'a']) {
            double val = dfs(next, dest, graph, visited);
            if (val != -1.0) {
                return weight * val;
            }
        }
    }
    return -1.0;
}

vector<double> solve(vector<vector<char>>& equations, vector<double>& values,
                     vector<vector<char>>& queries) {
    unordered_map<char, vector<pair<char, double>>> graph;
    for (int i = 0; i < equations.size(); i++) {
        char source = equations[i][0];
        char dest = equations[i][1];
        double value = 1.0 * values[i];
        graph[source].push_back({dest, value});
        graph[dest].push_back({source, 1 / value});
    }
    vector<double> ans;
    for (int i = 0; i < queries.size(); i++) {
        char source = queries[i][0];
        char dest = queries[i][1];
        if (!graph.count(source) || !graph.count(dest)) {
            ans.push_back(-1.0);
            continue;
        }
        vector<bool> visited(26, false);
        double res = dfs(source, dest, graph, visited);
        ans.push_back(res);
    }
    return ans;
}

int main() {
    vector<vector<char>> equations = {{'a', 'b'}, {'b', 'c'}, {'c', 'd'}};
    vector<double> values = {0.5, 2.5, 1.5};
    vector<vector<char>> queries = {{'a', 'd'}, {'b', 'd'}, {'d', 'e'}};
    vector<double> ans = solve(equations, values, queries);
    for (double i : ans) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
