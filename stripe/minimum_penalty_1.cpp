#include <bits/stdc++.h>
using namespace std;

int main() {
  string log;
  int closing_time;
  cin >> log;
  cin >> closing_time;
  int penalty = 0;
  for (int i = 0; i < log.size(); i++) {
    if (log[i] == 'N' && i < closing_time)
      penalty++;
    else if (log[i] == 'Y' && i >= closing_time)
      penalty++;
  }
  cout << penalty << endl;
}
