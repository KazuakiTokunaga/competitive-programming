#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  string s;
  cin >> s;

  int ans = 0;
  char cur = 'a';
  for (int a = 0; a < n; a++) {
      if (a == 0 or s[a] != cur) {
          ans += 1;
          cur = s[a];
      }
  }

  cout << ans << endl;
}