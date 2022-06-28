#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define all(x) (x).begin(),(x).end()

#include <bits/stdc++.h>
using namespace std;

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
    
    // 5x + 13y = gcd(5, 13)の解を求める
	ll a = 998244353, b = 595591169, s = 897581057;
    ll x, y;
    extgcd(a, -b, x, y);
    cout << x << " " << y << endl;

	cout << s / __gcd(a, b) << endl;
}