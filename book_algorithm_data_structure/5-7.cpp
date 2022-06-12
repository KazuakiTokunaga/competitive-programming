// 動的計画法（ナップサック問題）

#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int n;
    ll w;
    cin >> n >> w;

    vector<ll> weight(n), value(n);
    for (int i = 0; i < n; i++) {
        cin >> weight[i] >> value[i];
    }

    vector<vector<ll>> dp(n+1, vector<ll>(w+1, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= w; j++) {
            if (j-weight[i] >= 0){
                dp[i+1][j] = max(dp[i+1][j], dp[i][j-weight[i]] + value[i]);
            }

            dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
        }
    }
    
    cout << dp[n][w] << endl;
}