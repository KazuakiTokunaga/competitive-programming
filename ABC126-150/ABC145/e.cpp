#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<ll, ll>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define all(x) (x).begin(),(x).end()

int main() {
    int n, t;
    cin >> n >> t;

    vector<pii> dishes;
    rep(i, 0, n){
        int a, b;
        cin >> a >> b;
        dishes.push_back(make_pair(a, b));
    }

    sort(all(dishes));
    
    // dp[i][j]: i番目の料理までみたときの、j分後の満足度の最大値
    vector<vector<ll>> dp(n+1, vector<ll>(t + 3001, 0));
    rep(i, 1, n+1){
        ll a = dishes[i-1].first, b = dishes[i-1].second;
        rep(j, 0, t+3001){
            dp[i][j] = max(dp[i][j], dp[i-1][j]);
            if (j < t) dp[i][j+a] = max(dp[i][j+a], dp[i-1][j] + b);
        }
    }
 
    ll res = 0;
    rep(i, 0, t+3001){
        res = max(res, dp[n][i]);    
    }

    cout << res << endl;
}