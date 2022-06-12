#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)

int main() {
    int n, w;
    cin >> n >> w;

    vector<ll> a(200010, 0);
    rep(i, 0, n){
        int s, t, p;
        cin >> s >> t >> p;
        a[s] += p;
        a[t] -= p;
    }

    vector<ll> accum(200010, 0);
    partial_sum(a.begin(), a.end(), accum.begin());

    ll max_water = *max_element(accum.begin(), accum.end());   
    if (max_water > w) cout << "No" << endl;
    else cout << "Yes" << endl;
}