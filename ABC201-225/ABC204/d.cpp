#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)

int main() {
    int n;
    cin >> n;
    
    vector<int> t(n);
    rep(i, 0, n) cin >> t[i];

    ll total = accumulate(t.begin(), t.end(), (ll)0);
    
    vector<vector<int>> dp(n+1, vector<int>(100010,0));
    dp[0][0] = 1;
    rep(i, 0, n){
        int a = t[i];
        rep(j, 0, 100010){
            if (j+a < 100010) dp[i+1][j+a] = max(dp[i+1][j+a], dp[i][j]);
            dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
        }
    }

    long double target = (long double)total / 2;
    long double min_diff = pow(10, 9);
    rep(i, 0, 100010){
        if (dp[n][i] >= 1) min_diff = min(min_diff, abs(target - i));
    }
    
    cout << target + min_diff << endl;
}