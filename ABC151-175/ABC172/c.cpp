#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    
    vector<ll> b(m);
    for (int i = 0; i < m; i++) cin >> b[i];

    vector<ll> accum_a(n);
    partial_sum(a.begin(), a.end(), accum_a.begin(), [](ll t1, ll t2){return t1 + t2;});

    vector<ll> accum_b(m);
    partial_sum(b.begin(), b.end(), accum_b.begin(), [](ll t1, ll t2){return t1 + t2;});

    int j = (upper_bound(accum_b.begin(), accum_b.end(), (ll)k) - accum_b.begin()); // 個数

    ll cur = 0;
    if (j > 0) cur = accum_b[j-1];

    int res = j;
    bool finish = false;
    rep(i, 1, n+1){
        cur += a[i-1];
        while (cur > k){
            if (j == 0) {finish = true; break;}
            cur -= b[j-1];
            j--;
        }
        if (finish) break;
        res = max(res, i+j);
    }


    cout << res << endl;
}