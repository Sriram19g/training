#include <bits/stdc++.h>
using namespace std;

string getWord(const string& exp, int& i) {
    string res = "";
    while ('a' <= exp[i] && 'z' >= exp[i]) {
        res.push_back(exp[i]);
        i++;
    }
    return res;
}

unordered_set<string> dfs(const string& exp, int& i) {
    unordered_set<string> res;
    unordered_set<string> S;
    while (i < exp.size() && exp[i] != '}') {
        if (exp[i] == ',') {
            i++;
            for (auto& it : S) {
                res.insert(it);
            }
            S.clear();
        }
        unordered_set<string> t;
        if (exp[i] == '{') {
            i++;
            t = dfs(exp, i);
            i++;
        } else {
            t.insert(getWord(exp, i));
        }

        if (S.empty()) {
            S = t;
        } else {
            unordered_set<string> S2;
            for (auto& it : S) {
                for (auto& it1 : t) {
                    S2.insert(it + it1);
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

vector<string> brace_expansion(string exp) {
    int i = 0;
    unordered_set<string> res = dfs(exp, i);
    vector<string> ans;
    for (auto& i : res) {
        ans.push_back(i);
    }
    sort(ans.begin(), ans.end());
    return ans;
}
int main() {
    string s;
    cin >> s;
    vector<string> ans = brace_expansion(s);
    for (auto& i : ans) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
