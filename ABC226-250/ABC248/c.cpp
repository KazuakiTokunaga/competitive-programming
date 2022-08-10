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
    
    // dp[i][j]; i文字までみて総和がjである場合の和
    vector<vector<int>> dp(N+1, vector<int>(K+1, 0));
    dp[0][0] = 1;

    rep(i, 1, N+1){
        rep(j, 0, K){
            rep(k, 1, M+1){
                if (j+k > K) continue;
                dp[i][j+k] += dp[i-1][j];
                dp[i][j+k] %= MOD;
            }
        }
    }

    int res = 0;
    rep(i, 0, K+1){
        res += dp[N][i];
        res %= MOD;
    }
    cout << res << endl;
}