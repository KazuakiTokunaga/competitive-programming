#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll count(ll a, ll b, ll c) {
    ll a2 = ceil((long double)a / c);
    ll b2 = floor((long double)b / c);
    return b2 - a2 + 1;
}

int main() {
    ll a,b,c,d;
    cin >> a >> b >> c >> d;
    
    ll r1 = count(a,b,c);
    ll r2 = count(a,b,d);
    ll r3 = count(a,b, c / __gcd(c,d) * d);
    cout << (b-a+1) - r1 - r2 + r3 << endl;
}