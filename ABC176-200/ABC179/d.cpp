// 最初に思いついたが複雑な解法

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
            
            // (start~len) ~ startからj番目の区間の数を利用してiに至る場合の下図を加える。dp[i]][k]は到達方法の合計数
            if (start >= 1) dp[i][k] += dp[start][j], dp[i][k] %= MOD;

            accum[i] = dp[i][k] + accum[i-1], accum[i] %= MOD;
        };
        rep(j, 0, k){
            pii p = lr[j];
            int len = lens[j];
            int finish = max(0, i-len);
            dp[i][j] = accum[i] - accum[finish]; // j番目の区間の長さをlenとすると、(i-len)からiまでの到達方法の合計を記録しておく
            while (dp[i][j] < 0) dp[i][j] += MOD;
        }
    }
    
    cout << dp[n][k] << endl;
}