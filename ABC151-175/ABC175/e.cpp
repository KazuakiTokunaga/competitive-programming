#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define all(x) (x).begin(),(x).end()

vector<vector<int>> grid;

int main() {
    int R, C, K;
    cin >> R >> C >> K;

    grid.assign(R+1, vector<int>(C+1, 0));
    rep(i, 0, K){
        int r, c, v;
        cin >> r >> c >> v;
        grid[r][c] = v;
    }
    
    // dp[i][j][k]: i行j列目までみて、i行目で拾った個数がk個の時の最大値
    vector<vector<vector<ll>>> dp(R+1, vector<vector<ll>>(C+1, vector<ll>(4, 0)));
    
    rep(i, 1, R+1){
        rep(j, 1, C+1){
            int cur = grid[i][j];

            // 上から来る場合の最大値を確認
            ll max_above = 0;
            rep(k1, 0, 4){
                max_above = max(max_above, dp[i-1][j][k1]);
            }

            rep(k, 0, 4){
                
                // アイテムがある場合
                if (cur){
                    if (k == 0){
                        // 上から来て拾わない、左から来て拾わない
                        dp[i][j][k] = max(max_above, dp[i][j-1][k]); 
                    } else if (k == 1){
                        // 上から来て拾うか、左から来て拾う、左から来て拾わない
                        dp[i][j][k] = max(max(max_above+cur, dp[i][j-1][k-1]+cur), dp[i][j-1][k]); 
                    } else {
                        // 左から来て拾う、左からきて拾わない
                        dp[i][j][k] = max(dp[i][j-1][k-1]+cur, dp[i][j-1][k]);
                    }
                
                // アイテムがない場合
                } else {
                    if (k == 0){
                        //上から来て拾わないか、左から来て拾わないか
                        dp[i][j][k] = max(max_above, dp[i][j-1][k]);
                    } else {
                        //左から来て拾わない
                        dp[i][j][k] = dp[i][j-1][k];
                    }
                }
            }
        }
    }

    ll res = 0;
    rep(i, 0, 4){
        res = max(res, dp[R][C][i]);
    }
    cout << res << endl;

}

