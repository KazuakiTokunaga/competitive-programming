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

int main() {
    int n, k;
    cin >> n >> k;

    init();
    vector<ll> A(n);
    rep(i, 0, n) cin >> A[i];
    sort(all(A), greater<int>());

    ll res = 0;
    rep(i, 0, n){
        ll a = A[i];
        if (n-(i+1) < k-1) continue;
        res += a * C(n-(i+1), k-1) % MOD;
        res %= MOD;
    }
    reverse(all(A));
    rep(i, 0, n){
        ll a = A[i];
        if (n-(i+1) < k-1) continue;
        res -= a * C(n-(i+1), k-1) % MOD;
        res %= MOD;
        while (res<0) res += MOD;
    }
    cout << res << endl;
}