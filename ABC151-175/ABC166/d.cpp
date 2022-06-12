#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)

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
    ll x;
    cin >> x;

    if (x == 1) {
        cout << 0 << " " << -1 << endl;
    } else {
        auto factors = enum_divisors(x);        
        for (int r: factors) {
            rep(i, -1 * pow(10, 5), pow(10, 5)){
                ll a = i + r;
                if (pow((ll)a, 5) - pow((ll)i, 5) == x) {
                    cout << a << " " << i << endl;
                    return 0;
                }
            }
        }
    }
}