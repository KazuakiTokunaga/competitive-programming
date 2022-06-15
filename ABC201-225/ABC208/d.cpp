#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> dp(n+1, vector<int>(n+1, pow(10, 9)));
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        dp[a][b] = c;
    }

    rep(i, 1, n+1){
        dp[i][i] = 0;
    }

    ll ans = 0;
    rep(k, 1, n+1){
        rep(i, 1, n+1){
            rep(j, 1, n+1){
                dp[i][j] = min(dp[i][k]+dp[k][j], dp[i][j]);
            }
        }
        rep(i, 1, n+1){
            rep(j, 1, n+1){
                if (dp[i][j] != pow(10, 9)) ans += dp[i][j];
            }
        }
    }

    cout << ans << endl;
}