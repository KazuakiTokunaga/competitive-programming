#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
const ll MOD = pow(10,9) + 7;

string toBinary(int n){
    string r;
    while (n != 0){
        r += ( n % 2 == 0 ? "0" : "1" );
        n /= 2;
    }
	reverse(r.begin(), r.end());
    return r;
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
    int n;
    cin >> n;

    vector<pair<ll, ll>> count(63, {0,0});

    rep(i, 0, n){
        ll a;
        cin >> a;

        bitset<63> bs(a);
        rep(i, 0, 63){
            if (bs[i] == 1) count[i].second++;
            else count[i].first++;
        }
    }

    ll res = 0;
    rep(i, 0, 61){
        ll s = (count[i].first * count[i].second) % MOD;
        s *= pow_mod(2, i) % MOD;
        s %= MOD;
        res += s;
        res %= MOD;
    }

    cout << res << endl;
}