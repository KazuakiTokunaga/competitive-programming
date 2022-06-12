#include <bits/stdc++.h>
using namespace std;

int main() {
  int a,b;
  cin >> a >> b;
  
  int r;
  r = max(0, a-b*2);
  cout << r << endl;
}