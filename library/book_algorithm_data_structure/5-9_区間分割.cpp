// 動的計画法（区間分割）

#include <bits/stdc++.h>
using namespace std;
#define ll long long

constexpr int INF = 1000000000 + 8;

int main() {
    int n;
    cin >> n;
    
    vector<vector<int>> c(n+1, vector<int>(n+1));
    for (int i = 0; i < n+1; i++) {
        for (int j = 0; j < n+1; j++) {
            cin >> c[i][j];
        }
    }

    vector<ll> dp(n+1, INF);
    dp[0] = 0;

    for (int i = 0; i < n+1; i++) {
        for (int j = 0; j < i; j++) {
            dp[i] = min(dp[i], dp[j]+c[j][i]);
        }
    }

    cout << dp[n] << endl;
}