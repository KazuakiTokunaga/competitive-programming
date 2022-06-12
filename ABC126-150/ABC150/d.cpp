#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)

int main() {
    ll n, m;
    cin >> n >> m;

    ll a;
    cin >> a;

    rep(i, 1, n){
        ll b;
        cin >> b;

        ll gcd = __gcd(a, b);
        if ((a / gcd) % 2 == 0 or (b / gcd) % 2 == 0){
            cout << 0 << endl;
            return 0;
        }

        ll lcm = a / gcd * b;
        if (lcm > 2*m) {
            cout << 0 << endl;
            return 0;
        }
        a = lcm;
    }


    ll start = a / 2;
    ll res = 0;
    if (m >= start){
        res = 1 + (m - start) / a;
    }
    
    cout << res << endl;
}