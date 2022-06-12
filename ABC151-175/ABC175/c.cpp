#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)

int main() {
    ll x, k, d;
    cin >> x >> k >> d;

    ll cur = x;
    ll count = abs(x) / d;
    if (k < count) count = k;

    if (x < 0) cur += count * d;
    else cur -= count * d;

    if ((k-count) % 2 == 0) cout << abs(cur) << endl;
    else if (cur < 0) cout << abs(cur + d) << endl;
    else cout << abs(cur - d) << endl;
}