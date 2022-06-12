#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)

int main() {
    int n;
    cin >> n;
    
    vector<ll> a(n);
    rep(i, 0, n) cin >> a[i];
    
    sort(a.begin(), a.end());
    
    ll res = 0;
    rep(i, 0, n){
        res -= a[i] * (n-1 - i);
        res += a[i] * i;
    }

    cout << res << endl;
}