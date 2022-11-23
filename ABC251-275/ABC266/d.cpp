#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define all(x) (x).begin(),(x).end()
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false;}

int main() {
    int N;
    cin >> N;
    
    vector<pii> ts(100010, {0,0});
    rep(i, 0, N){
        int t, x, a;
        cin >> t >> x >> a;
        ts[t] = {x, a};
    }

    // dp[i][j]: i秒後に位置jにいるときの最大値
    vector<vector<ll>> dp(100020, vector<ll>(5, -1));
    auto[x0, a0] = ts[0];
    dp[0][0] = a0;

    rep(i, 1, 100010){
        auto[x, a] = ts[i];
        rep(j, 0, 5){
            ll p = 0;
            if (x == j) p = a;

            if (j-1 >= 0 and dp[i-1][j-1] > -1) chmax(dp[i][j], dp[i-1][j-1] + p);
            if (dp[i-1][j] > -1) chmax(dp[i][j], dp[i-1][j] + p);
            if (j+1 <= 4 and dp[i-1][j+1] > -1) chmax(dp[i][j], dp[i-1][j+1] + p);
        }
    }

    ll res = 0;
    rep(i, 0, 5) chmax(res, dp[100001][i]);
    cout << res << endl;
}