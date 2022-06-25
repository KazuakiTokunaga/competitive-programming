#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define all(x) (x).begin(),(x).end()
const ll MOD = pow(10, 9) + 7;

int main() {
    string s;
    cin >> s;
    int n = s.size();

    vector<vector<ll>>dp(n+1, vector<ll>(2, 0));
    dp[0][1] = 2; // どちらかに1, 超える可能性がある
    dp[0][0] = 1; // 0

    rep(i, 1, n){
        int a = int(s[i]-'0');
        if (a) {
            dp[i][1] = (dp[i-1][1] * 2) % MOD; // 1をどちらかに立てる場合
            dp[i][0] = (dp[i-1][1] + (dp[i-1][0] * 3)) % MOD; // どれでもOK.
        } else {
            dp[i][1] = dp[i-1][1] % MOD; // ゼロのみ
            dp[i][0] = dp[i-1][0] * 3 % MOD; //
        }
   }


   cout << (dp[n-1][0] + dp[n-1][1] + MOD) % MOD << endl;
}