#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
const int MOD = pow(10,9) + 7;

int main() {
    string s;
    cin >> s;

    int n = s.size();
    vector<vector<ll>> dp(101010, vector<ll>(13));

    dp[0][0] = 1;
    rep(i, 0, n){
        rep(j, 0, 13){
            if (s[i]=='?'){
                rep(k, 0, 10){
                    int t = (j*10 + k) % 13;
                    dp[i+1][t] += dp[i][j];
                    dp[i+1][t] %= MOD;
                }
            } else {
                int t = (j*10 + (int)(s[i]-'0')) % 13;
                dp[i+1][t] += dp[i][j];
                dp[i+1][t] %= MOD;
            }
        }
    }

    cout << dp[s.size()][5] << endl;
    
}