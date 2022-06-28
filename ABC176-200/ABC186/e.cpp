#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define all(x) (x).begin(),(x).end()

// ax + by = gcd(a, b)の解(x,y)を求める
ll extgcd(ll a, ll b, ll &x, ll &y){
    ll d = a;
    if (b != 0){
        d = extgcd(b, a%b, y, x);
        y -= (a/b) * x;
    } else {
        x = 1; y = 0;
    }
    return d;
}

int main() {
    int T;
    cin >> T;

    rep(i, 0, T){
        int N, S, K;
        cin >> N >> S >> K;

        if (S % __gcd(N, -K) != 0) {cout << -1 << endl; continue;}
        
        ll x, y;
        extgcd(N, -K, x, y);
        y *= (S / __gcd(N, -K));
        x *= (S / __gcd(N, -K));
        ll lcm = K / __gcd(N, K) * N;
        ll ak = N / __gcd(N, K);
        ll an = K / __gcd(N, K);
        ll bk = abs(y) / ak;
        ll bn = abs(x) / an;
        if (y < 0 or x < 0) {
            ll b = max(bk, bn);
            y += ak * (b+1);
            x += an * (b+1);
        }
        if (y - ak > 0 and x - an > 0){
            ll b = min(bk, bn);
            y -= ak * b;
            x -= an * b;
        }


        cout << y << endl;
    }
    
    
}