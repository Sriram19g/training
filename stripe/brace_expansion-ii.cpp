#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

string getword(const string& expr, int& i) {
    string res;
    while ('a' <= expr[i] && 'z' >= expr[i]) {
        res.push_back(expr[i]);
        i++;
    }
    return res;
}

unordered_set<string> dfs(const string& expr, int& i) {
    unordered_set<string> res;
    unordered_set<string> S;

    while (i < expr.size() && expr[i] != '}') {
        if (expr[i] == ',') {
            i++;
            for (auto& i : S)
                res.insert(i);
            S.clear();
        }
        unordered_set<string> t;
        if (expr[i] == '{') {
            i++;
            t = dfs(expr, i);
            i++;
        } else {
            t.insert(getword(expr, i));
        }

        if (S.empty()) {
            S = t;
        } else {
            unordered_set<string> S2;
            for (auto& it1 : S) {
                for (auto& it2 : t) {
                    S2.insert(it1 + it2);
                }
            }
            swap(S, S2);
        }
    }
    for (auto& it : S) {
        res.insert(it);
    }
    return res;
}

vector<string> brace_expansion(string expression) {
    int i = 0;
    unordered_set<string> S = dfs(expression, i);

    vector<string> ans;
    for (auto& i : S) {
        ans.push_back(i);
    }
    sort(ans.begin(), ans.end());
    return ans;
}

int main() {
    string expr;
    cin >> expr;
    vector<string> ans = brace_expansion(expr);
    for (auto& i : ans) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
