#include <bits/stdc++.h>
using namespace std;
int main() {
  string log;
  cin >> log;
  int cur = 0, maxi = 0, early = 0;
  for (int i = 0; i < log.size(); i++) {
    if (log[i] == 'Y')
      cur++;
    else
      cur--;
    if (maxi < cur) {
      maxi = cur;
      early = i + 1;
    }
  }

  cout << early << endl;
}
