#include <bits/stdc++.h>
using namespace std;

int main() {
  int a,b;
  cin >> a >> b;
  
  int r = -1;
  if(a <= 9 and b<= 9){
    r = a*b;
  };
  cout << r << endl;  
}