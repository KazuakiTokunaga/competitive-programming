// 逆元を用いればMODのうえで割り算が可能
// LCMが大きすぎても、逆元を用いればMODの値にして計算できる

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define all(x) (x).begin(),(x).end()
const int MOD = pow(10, 9) + 7;

vector<pii> prime_factorize(ll N) {
    vector<pii> res;
    for (ll a = 2; a * a <= N; ++a) {
        if (N % a != 0) continue;
        ll ex = 0; // 指数

        while (N % a == 0) {
            ++ex;
            N /= a;
        }

        res.push_back({a, ex});
    }

    // 最後に残った数について
    if (N != 1) res.push_back({N, 1});
    return res;
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

int main() {
    int n;
    cin >> n;

    vector<int> A(n);
    rep(i, 0, n) cin >> A[i];

    map<int, int> factors_cnt;
    rep(i, 0, n){
        int a = A[i];
        auto factors = prime_factorize(a);
        for (auto p: factors) {
            factors_cnt[p.first] = max(factors_cnt[p.first], p.second);
        }
    }

    ll lcm = 1;
    for (auto& [j, cnt]: factors_cnt) {
        lcm *= pow_mod(j, cnt);
        lcm %= MOD;
    }

    ll res = 0;
    rep(i, 0, n){
        int a = A[i];

        ll b = lcm * inv(a);
        res += b;
        res %= MOD;
    }
    cout << res << endl;
}