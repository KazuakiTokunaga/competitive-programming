#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)

int main() {
    int n;
    cin >> n;

    vector<vector<ll>>dp(n+1, vector<ll>(2, 0));
    dp[0][1] = 1; dp[0][0] = 1;

    rep(i, 1, n+1){
        string s;
        cin >> s;
        if (s == "AND"){
            dp[i][1] = dp[i-1][1];
            dp[i][0] = dp[i-1][1] + 2 * dp[i-1][0];
        } else {
            dp[i][1] = 2 * dp[i-1][1] + dp[i-1][0];
            dp[i][0] = dp[i-1][0];
        }
    }

    cout << dp[n][1] << endl;

}