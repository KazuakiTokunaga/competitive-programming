#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define all(x) (x).begin(),(x).end()
const int MOD = 998244353;

int main() {
    int N;
    cin >> N;
    
    vector<int> A(N);
    rep(i, 0, N) cin >> A[i];

    ll res = N;
    rep(i, 2, N+1){

        // dp[j][k][l]: j番目までの整数からk個選んであまりがlである個数
        vector<vector<vector<ll>>> dp(N+1, vector<vector<ll>>(i+1, vector<ll>(i, 0)));
        dp[0][0][0] = 1;
        rep(j, 0, N){
            rep(k, 0, i+1){
                rep(l, 0, i){
                    if (k+1 <= i){
                        // 選ぶ
                        int nxt_l = (l + A[j]) % i;
                        dp[j+1][k+1][nxt_l] += dp[j][k][l];
                        dp[j+1][k+1][nxt_l] %= MOD;
                    }

                    // 選ばない
                    dp[j+1][k][l] += dp[j][k][l];
                    dp[j+1][k][l] %= MOD;
                }
            }
        }

        res += dp[N][i][0];
        res %= MOD;
    }

    cout << res << endl;
}