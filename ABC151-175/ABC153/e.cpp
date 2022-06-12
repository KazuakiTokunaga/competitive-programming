#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
const ll INF = 1LL << 60;

int main() {
    int h, n;
    cin >> h >> n;

    vector<pair<int, int>> magics;
    ll max_a = 0;
    rep(i, 0, n){
        int a, b;
        cin >> a >> b;
        magics.push_back(make_pair(a, b));
        max_a = max((ll)a, max_a);
    }

    vector<ll> dp(h+max_a+1, INF);
    dp[0] = 0;
    ll res = INF;
    rep(i, 1, h+max_a+1){
        rep(j, 0, n){
            int a = magics[j].first, b = magics[j].second;
            if (i-a < 0) continue;
            dp[i] = min(dp[i], dp[i-a] + b);
            if (i >= h) res = min(res, dp[i]);
        }
    }

    cout << res << endl;
}