#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  double ans;
  if (n % 2 == 0) {
      ans = 0.5;
  } else {
      ans = ((n+1) / 2.0) / n;
  }
  
  cout << setprecision(10) << ans << endl;
}