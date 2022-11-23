// 行列累乗
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define all(x) (x).begin(),(x).end()
#define mat vector<vector<ll>>
const int MOD = 10000;

/// 行列積
mat mat_mul(mat &a, mat &b) {
  mat res(a.size(), vector<ll>(b[0].size()));
  for (int i = 0; i < a.size(); i++) {
    for (int j = 0; j < b[0].size(); j++) {
      for (int k = 0; k < b.size(); k++) {
        (res[i][j] += a[i][k] * b[k][j]) %= MOD;
      }
    }
  }
  return res;
}

/// 行列累乗
mat mat_pow(mat a, long long n) {
  mat res(a.size(), vector<ll>(a.size()));
  // 単位行列で初期化
  for (int i = 0; i < a.size(); i++)
    res[i][i] = 1;
  // 繰り返し二乗法
  while (n > 0) {
    if (n & 1) res = mat_mul(a, res);
    a = mat_mul(a, a);
    n >>= 1;
  }
  return res;
}


int main() {
    int n;
    cin >> n;
    
    mat A(2, vector<ll>(2, 0));
    A[0][0] = 1; A[0][1] = 1;
    A[1][0] = 1; A[1][1] = 0;
    A = mat_pow(A, n);
    cout << A[1][0] << endl;
}