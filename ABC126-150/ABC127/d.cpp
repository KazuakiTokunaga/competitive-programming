#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    
    vector<pair<int,ll>> bc(m);
    rep(i, 0, m){
        int b, c;
        cin >> b >> c;
        bc.push_back(make_pair(b,c));
    }

    sort(bc.begin(), bc.end(), [](auto b, auto c){
        return b.second > c.second;
    });

    vector<ll> replacing;
    rep(i, 0, m){
        rep(j, 0, bc[i].first){
            if (replacing.size() == n) break;
            replacing.push_back(bc[i].second);
        }
        if (replacing.size() == n) break;
    }
    sort(replacing.begin(), replacing.end());

    ll res = 0;
    rep(i, 0, n){
        if (replacing.empty() or a.back() > replacing.back()){
            res += a.back();
            a.pop_back();
        } else {
            res += replacing.back();
            replacing.pop_back();
        }
    }
    cout << res << endl;

}