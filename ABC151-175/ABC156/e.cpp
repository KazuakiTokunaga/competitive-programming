#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define all(x) (x).begin(),(x).end()
const int MOD = pow(10, 9) + 7;

ll f[1010100];
void init() {
    f[0] = 1;
    rep(i, 1, 1010100) f[i] = (f[i - 1] * i) % MOD;
}

ll inv(ll x) {
    ll res = 1;
    ll k = MOD - 2;
    ll y = x;
    while (k) {
        if (k & 1) res = (res * y) % MOD;
        y = (y * y) % MOD;
        k /= 2;
    }
    return res;
}

ll C(int n, int k) {
    ll a = f[n]; // = n!
    ll b = f[n-k]; // = (n-k)!
    ll c = f[k]; // = k!

    ll bc = (b * c) % MOD;

    return (a * inv(bc)) % MOD;
}

ll pow_mod(ll x, ll n) {
    ll ret = 1;
    while (n > 0) {
        if (n & 1) ret = (ret * x) % MOD;
        x = (x * x) % MOD;
        n >>= 1;  // n を1bit 左にずらす
    }
    return ret;
}

int main() {
    int n, k;
    cin >> n >> k;

    init();
    int maxi = min(n-1, k);

    ll res = 0;
    rep(i, 0, maxi+1){ // iは0人の部屋の数
        ll c = C(n, i);
        ll a = f[n-1] * inv(f[n-i-1]) % MOD * inv(f[i]) % MOD;
        while (a < 0) {a += MOD;}
        res += a * c % MOD;
        res %= MOD;
    }
    cout << res << endl;
}