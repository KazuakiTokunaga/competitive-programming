#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
const ll MOD = pow(10, 9) + 7;

// nCk mod pをO(N+log p)で求める
// https://blog.hamayanhamayan.com/entry/2018/06/06/210256

ll f[1010100];
void init() {
    f[0] = 1;
    rep(i, 1, 1010100) f[i] = (f[i - 1] * i) % MOD;
}

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

ll C(int n, int k) {
    if (n < k or n < 0) return 0;

    ll a = f[n]; // = n!
    ll b = f[n-k]; // = (n-k)!
    ll c = f[k]; // = k!

    ll bc = (b * c) % MOD;

    return (a * inv(bc, MOD)) % MOD;
}

int main() {
    init(); // 最初にnまでを初期化
    cout << C(23523,1453) << endl;
}