#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
const ll MOD = pow(10, 9) + 7;

vector<ll> fact_inv, inv;
void init_nCk(ll SIZE) {
    fact_inv.resize(SIZE + 5);
    inv.resize(SIZE + 5);
    fact_inv[0] = fact_inv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < SIZE + 5; i++) {
        inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
        fact_inv[i] = fact_inv[i - 1] * inv[i] % MOD;
    }
}

ll nCk(ll n, ll k) {
    ll ans = 1;
    for (int i = n; i >= n - k + 1; i--) {
        ans *= i;
        ans %= MOD;
    }
    return ans * fact_inv[k] % MOD;
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
    ll n, a, b;
    cin >> n >> a >> b;

    ll total = pow_mod(2, n) - 1;

    init_nCk(max(a,b)+1);
    ll res = total - nCk(n, a) - nCk(n, b);
    while (res < 0) res += MOD;
    cout << res << endl;    
}