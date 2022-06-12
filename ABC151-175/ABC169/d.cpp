#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)

// 素因数分解
vector<pair<ll, ll> > prime_factorize(ll N) {
    vector<pair<ll, ll> > res;
    for (ll a = 2; a * a <= N; ++a) {
        if (N % a != 0) continue;
        ll ex = 0; // 指数

        // 割れる限り割り続ける
        while (N % a == 0) {
            ++ex;
            N /= a;
        }

        // その結果を push
        res.push_back({a, ex});
    }

    // 最後に残った数について
    if (N != 1) res.push_back({N, 1});
    return res;
}

int main() {
    ll n;
    cin >> n;

    auto factors = prime_factorize(n);

    int res = 0;
    rep(i, 0, factors.size()){
        auto p = factors[i];

        int count = 1;
        while (p.second >= count){
            p.second -= count;
            res++;
            count++;
        }
    }
    
    cout << res << endl;
}