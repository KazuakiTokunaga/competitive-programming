#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define all(x) (x).begin(),(x).end()
const int MOD = 998244353;

ll f[310100];
void init() {
    f[0] = 1;
    rep(i, 1, 310100) f[i] = (f[i - 1] * i) % MOD;
}

ll inv(ll x) {
    ll res = 1;
    ll k = MOD - 2; // MODを変えれば他の法に対する逆元を出力する
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
    int N, M, K;
    cin >> N >> M >> K;

    init();
    ll res = 0;

    rep(k, 0, K+1){
        ll cnt;
        int n = N-k;
        cnt = (C(N-1, k) * M % MOD) * pow_mod(M-1, n-1) % MOD;
        // cout << k << " " << n << " " << cnt << endl;
        res += cnt; res %= MOD;
    }
    cout << res << endl;
}