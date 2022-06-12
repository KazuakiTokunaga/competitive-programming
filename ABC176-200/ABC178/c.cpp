#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
const int MOD = pow(10, 9) + 7;

int main() {
    int n;
    cin >> n;
    
    ll res = 1;
    rep(i, 0, n){
        res *= 10;
        res %= MOD;
    }

    ll c = 1;
    rep(i, 0, n){
        c *= 8;
        c %= MOD;
    }

    ll a = 1;
    rep(i, 0, n){
        a *= 9;
        a %= MOD;
    } 

     ll s = ((a * 2) % MOD - c);
     while (s < 0) s += MOD;

     res = res - s;
     res %= MOD;
     while (res < 0) res += MOD;

    cout << res << endl;
}