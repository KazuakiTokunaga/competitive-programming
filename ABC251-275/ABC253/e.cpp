#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define all(x) (x).begin(),(x).end()
const int MOD = 998244353;

int main() {
    int N, M, K;
    cin >> N >> M >> K;

    vector<vector<ll>> dp(N, vector<ll>(M+1, 0));
    vector<vector<ll>> accum(N, vector<ll>(M+1, 0));
    rep(i, 1, M+1) {
        dp[0][i] = 1; 
        accum[0][i] = dp[0][i] + accum[0][i-1];
    }

    rep(i, 1, N){
        rep(j, 1, M+1){
            if (j-K > 0) {
                dp[i][j] += accum[i-1][j-K];
            }
            if (j+K <= M) {
                dp[i][j] += accum[i-1][M] - accum[i-1][j+K-1];
            }
            if (K == 0) dp[i][j] -= dp[i-1][j];

            dp[i][j] %= MOD;
            while (dp[i][j] < 0) dp[i][j] += MOD;

            accum[i][j] = dp[i][j] + accum[i][j-1];
            accum[i][j] %= MOD;
        }
    }

    cout << accum[N-1][M] << endl;
}