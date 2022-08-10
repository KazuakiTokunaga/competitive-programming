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
    
    vector<vector<int>> dp(N, vector<int>(10, 0));
    rep(i, 0, N){
        rep(j, 1, 10){
            if (i == 0) {dp[i][j] = 1; continue;}
            
            if (j-1>0) {dp[i][j] += dp[i-1][j-1]; dp[i][j] %= MOD;}
            dp[i][j] += dp[i-1][j]; dp[i][j] %= MOD;
            if (j+1<10) {dp[i][j] += dp[i-1][j+1]; dp[i][j] %= MOD;}
        }
    }

    int res = 0;
    rep(i, 1, 10) {res += dp[N-1][i]; res %= MOD;}
    cout << res << endl;
    
}