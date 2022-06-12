#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
const int MOD = 998244353;

int main() {
    int n, k;
    cin >> n >> k;
    
    vector<pii> lr;
    vector<int> lens;
    rep(i, 0, k){
        int l, r;
        cin >> l >> r;
        lr.push_back({l, r});
        lens.push_back(r-l+1);
    }

    vector<vector<int>> dp(n+1, vector<int>(k+1, 0));
    vector<int> accum(n+1, 0);
    rep(i, 0, k+1) dp[1][i] = 1;
    accum[1] = 1;

    rep(i, 2, n+1){
        rep(j, 0, k){
            pii p = lr[j];
            int start = i - p.first;
            // if (i == 4 and j == 0) cout << start << " " << dp[start][j] << endl;
            if (start >= 1) dp[i][k] += dp[start][j], dp[i][k] %= MOD;
            accum[i] = dp[i][k] + accum[i-1], accum[i] %= MOD;
        };
        rep(j, 0, k){
            pii p = lr[j];
            int len = lens[j];
            int finish = max(0, i-len);
            // if (i == 3 and j == 0) cout << finish << " " << accum[i] << " " << accum[finish] << endl;
            dp[i][j] = accum[i] - accum[finish];
            while (dp[i][j] < 0) dp[i][j] += MOD;
            
        }
        // cout << "i = " << i << ": ";
        // for (auto i: dp[i]) {cout << i << ' ';} cout << endl;
    }
    // cout << "accum: ";
    // for (auto i: accum) {cout << i << ' ';} cout << endl;
    
    cout << dp[n][k] << endl;
}