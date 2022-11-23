#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define all(x) (x).begin(),(x).end()
const ll MOD = 998244353;

int main() {
    int T;
    cin >> T;

    vector<vector<ll>> dp(1000100, vector<ll>(4, 0));
    rep(_, 0, T){
        int n; string s;
        cin >> n >> s;

        int r = (n+1) / 2;
        rep(i, 0, r){
            dp[i][0] = dp[i][1] = dp[i][2] = dp[i][3] = 0;

            ll c = int(s[i]-'A');
            ll cr = int(s[n-1 - i] - 'A');

            if (!i){
                dp[i][0] = c; // sを超えないことが確定している数
                if (c < cr) dp[i][1] = 1; // 先頭からはsと同じ状況、末尾はOK
                else if (c == cr) dp[i][2] = 1; // 先頭からも末尾からもsと同じ状況
                else dp[i][3] = 1; // 先頭からはsと同じ状況、末尾がNG

                continue;
            }

            dp[i][0] += (dp[i-1][0] * 26) % MOD + c;
            
            if (i < (n-1) - i){
                if (c < cr) dp[i][1] = 1;
                else if (c == cr) {
                    dp[i][1] = dp[i-1][1];
                    dp[i][2] = dp[i-1][2]; 
                    dp[i][3] = dp[i-1][3];
                }
                else dp[i][3] = 1;
            } else {
                dp[i][1] = dp[i-1][1];
                dp[i][2] = dp[i-1][2];
            }


            dp[i][0] %= MOD;
            dp[i][1] %= MOD;
            dp[i][2] %= MOD;
            dp[i][3] %= MOD;
        }

        cout << (dp[r-1][0] + dp[r-1][1] + dp[r-1][2]) % MOD << endl;
    }
}