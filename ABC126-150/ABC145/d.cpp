#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
const ll MOD = pow(10, 9) + 7;

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


int main() {
    ll x, y;
    cin >> x >> y;

    if ((ll)(x+y) % 3 != 0){
        cout << 0 << endl;
        return 0;
    }

    ll a, b;
    a = (2*y - x) / 3;
    b = (2*x - y) / 3;
    if (a < 0 or b < 0) {
        cout << 0 << endl;
        return 0;
    }
    init();

    cout << C(a+b, a) << endl;
}