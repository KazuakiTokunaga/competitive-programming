#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)

int main() {
    int n;
    ll k;
    cin >> n >> k;

    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<ll> accum(n);
    partial_sum(a.begin(), a.end(), accum.begin());
    
    int i = 0, j = 0;
    ll ans = 0;
    while (true){
        j = max(j, i);

        ll s = accum[j];
        if (i>0) s -=accum[i-1];

        if (s < k and j < n) {
            j++;
        } else if (s >= k and j < n){
            ans += n-j;
            i++;
        } else {
            break;
        }
    }

    cout << ans << endl;
}