#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
const int MOD = pow(10, 9) + 7;

int main() {
    int n;
    cin >> n;

    vector<ll> dp(2001, 1);
    rep(i, 0, 3){
        dp[i] = 0;
    }
    rep(i, 3, 6){
        dp[i] = 1;
    }
    rep(i, 6, 2002){
        rep(j, 3, i-2){
            dp[i] += dp[i-j];
            dp[i] %= MOD;
        }
    }

    cout << dp[n] << endl;
    
}