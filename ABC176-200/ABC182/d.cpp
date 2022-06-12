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
    
    vector<ll> accum(n);
    partial_sum(a.begin(), a.end(), accum.begin());

    vector<ll> accum_accum(n);
    partial_sum(accum.begin(), accum.end(), accum_accum.begin());

    ll res = 0;
    ll max_accum_accum = (1LL << 60) * -1;
    ll id = 0;
    rep(i, 0, n-1){
        if (max_accum_accum < accum_accum[i]) {
            max_accum_accum = accum_accum[i];
            id = i;
        }
    }

    if (id+2 == n) id += 1;
    ll max_accum = 0;
    rep(i, 0, id+1){
        if (max_accum < accum[i]){
            max_accum = accum[i];
        }
    }

    if (max_accum_accum + max_accum < 0 and accum_accum[n-1] < 0) cout << 0 << endl;
    else if (max_accum_accum + max_accum < accum_accum[n-1]) cout << accum_accum[n-1] << endl;
    else cout << max_accum_accum + max_accum << endl;

    // for (auto i: accum) {cout << i << ' ';} cout << endl;
    // for (auto i: accum_accum) {cout << i << ' ';} cout << endl;

}