#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
const int MOD = pow(10, 9) + 7;

int main() {
    string s;
    cin >> s;

    int n = s.size();
    vector<vector<int>> dp(8, vector<int>(n, 0));
    string chokudai = "chokudai";

    rep(i, 0, 8){
        char c = chokudai[i];
        int cur = 0;
        rep(j, 0, n){
            if (i==0){
                if (s[j] == c) cur++;
                dp[i][j] = cur;
            } else {
                if (s[j] == c) {cur += dp[i-1][j]; cur %= MOD;}
                dp[i][j] = cur;
            }

            dp[i][j] %= MOD;
        }
    }

    cout << dp[7][n-1] << endl;
}