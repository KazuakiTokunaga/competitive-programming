#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
const ll MOD = pow(10, 9) + 7;

// nCkの計算で、nが巨大なときに、O(k)で求める
// https://algo-logic.info/combination/#toc_id_1_2

vector<ll> fact_inv, inv;
void init(ll k) {
    fact_inv.resize(k + 5);
    inv.resize(k + 5);
    fact_inv[0] = fact_inv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < k + 5; i++) {
        inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
        fact_inv[i] = fact_inv[i - 1] * inv[i] % MOD;
    }
}

ll C(ll n, ll k) {
    ll ans = 1;
    for (int i = n; i >= n - k + 1; i--) {
        ans *= i;
        ans %= MOD;
    }
    return ans * fact_inv[k] % MOD;
}

int main() {
    init(100000); // 最初にkまでを初期化
    cout << C(pow(10, 9), 20294) << " " << C(pow(10, 9), 2324) << endl;
}