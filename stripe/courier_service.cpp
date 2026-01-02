#include <bits/stdc++.h>
using namespace std;

int minCost(string expr, string source, string dest) {
    string start, stop, service;
    int cost = 0;
    unordered_map<string, vector<pair<int, pair<string, string>>>> graph;
    int comma = 0;
    for (char i : expr) {
        if (('a' <= i && i <= 'z') || ('A' <= i && i <= 'Z')) {
            if (comma == 0)
                start.push_back(i); // start
            else if (comma == 1)
                stop.push_back(i); // stop
            else if (comma == 2)
                service.push_back(i); // service
        } else if ('0' <= i && i <= '9' && comma == 3) {
            int num = i - '0';
            cost = cost * 10 + num;
        } else if (i == ',')
            comma++;
        else if (i == ':') {
            graph[start].push_back({cost, {stop, service}});
            start.clear();
            stop.clear();
            service.clear();
            cost = 0;
            comma = 0;
        }
    }
    graph[start].push_back({cost, {stop, service}}); // for last data
    start.clear();
    stop.clear();
    service.clear();
    cost = 0;
    comma = 0;

    unordered_map<string, int> dist;
    priority_queue<pair<int, string>, vector<pair<int, string>>, greater<>> q;

    for (auto& i : graph) {
        dist[i.first] = INT_MAX;
    }

    dist[source] = 0;

    q.push({0, source});

    while (!q.empty()) {
        int cost = q.top().first;
        string place = q.top().second;
        q.pop();
        if (place == dest) {
            return cost;
        }
        if (cost > dist[place])
            continue;

        for (auto& i : graph[place]) {
            int w = i.first;
            string next = i.second.first;
            if (!dist.count(next) || dist[next] > cost + w) {
                dist[next] = cost + w;
                q.push({dist[next], next});
            }
        }
    }
    return INT_MAX;
}
int main() {
    string s;
    cin >> s;
    cout << minCost(s, "US", "UK") << endl;
    return 0;
}
