#include <bits/stdc++.h>
using namespace std;
void solve(int index, vector<vector<char>>& options, vector<string>& ans, string& current) {
    if (index == options.size()) {
        ans.push_back(current);
        return;
    }
    for (char& i : options[index]) {
        current.push_back(i);
        solve(index + 1, options, ans, current);
        current.pop_back();
    }
}
int main() {
    string exp;
    cin >> exp;
    vector<vector<char>> options;
    int i = 0;
    while (i < exp.size()) {
        if (exp[i] == '{') {
            vector<char> group;
            i++;
            while (exp[i] != '}') {
                if (exp[i] != ',')
                    group.push_back(exp[i]);
                i++;
            }
            options.push_back(group);
            i++;
        } else {
            options.push_back({exp[i]});
            i++;
        }
    }
    for (int j = 0; j < options.size(); j++) {
        for (int k = 0; k < options[j].size(); k++) {
            cout << options[j][k] << " ";
        }
        cout << endl;
    }
    vector<string> ans;
    string current = "";
    solve(0, options, ans, current);
    for (string s : ans) {
        cout << s << " , ";
    }
    cout << endl;

    return 0;
}
