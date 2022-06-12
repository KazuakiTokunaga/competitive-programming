#include <bits/stdc++.h>
using namespace std;
#define ll long long

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
    ll a = 12,b = 18;
    //cin >> a >> b;

    ll gcd = __gcd(a,b);
    auto result = prime_factorize(gcd);

    cout << result.size() + 1 << endl;
}