#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
const int MOD = pow(10,9) + 7;

int main() {
    int n, k;
    cin >> n >> k;
    
    vector<vector<ll>> dp(2010, vector<ll>(2010));
    rep(i, 0, n+1){
        dp[i][0] = 1;
        dp[i][i] = 1;
    }
    rep(j, 1, n+1){
        rep(k, 1, j){
            dp[j][k] = dp[j-1][k] + dp[j-1][k-1];
            dp[j][k] %= MOD;
        }
    }

    rep(i, 1, k+1){
        cout << (dp[n-k+1][i] % MOD * dp[k-1][i-1] % MOD) % MOD << endl;
    }
}