#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define all(x) (x).begin(),(x).end()
const int MOD = 998244353;

// 法mでのxの逆元を求める（mは素数）
ll inv(ll x, ll m) {
    ll res = 1;
    ll k = m - 2;
    ll y = x;
    while (k) {
        if (k & 1) res = (res * y) % m;
        y = (y * y) % m;
        k /= 2;
    }
    return res;
}


int main() {
    ll N;
    cin >> N;
    
    ll cur = 10;
    ll res = 0;
    while (true){
        if (N > cur-1){
            ll m = (cur - cur / 10) % MOD;
            res += (1 + m) * m % MOD * inv(2, MOD) % MOD;
            res %= MOD;
            cur *= 10;
        } else {
            ll m = (N+1 - cur / 10) % MOD;
            res += (1 + m) * m % MOD * inv(2, MOD) % MOD;
            res %= MOD;
            break;
        }
    }

    cout << res << endl;
}