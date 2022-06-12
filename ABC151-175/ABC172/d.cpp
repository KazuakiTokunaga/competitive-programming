#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
using P = pair<int, int>;

template <typename T>
vector<T> smallest_prime_factor(T n) {
  vector<T> spf(n + 1);
  for (T i = 0; i <= n; i++) spf[i] = i;
  for (T i = 2; i * i <= n; i++) {
    if (spf[i] == i) {
      for (T j = i * i; j <= n; j += i) {
        if (spf[j] == j) spf[j] = i;
      }
    }
  }
  return spf;
}

template <typename T>
map<T, T> prime_factolization(T x, vector<T> &spf) {
  map<T, T> mp;
  while (x != 1) {
    mp[spf[x]]++;
    x /= spf[x];
  }
  return mp;
}

int main() {
    int max = pow(10, 7);
    auto spf = smallest_prime_factor(max);

    int n;
    cin >> n;
    ll res = 0;
    rep(i, 1, n+1){
        auto p_fact = prime_factolization(i, spf);
        ll count = 1;
        for (auto num: p_fact) {
             count *= (num.second + 1);
        }
        res += i * count;
    }

    cout << res << endl;

 }