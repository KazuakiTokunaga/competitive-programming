// 動的計画法（編集距離）

#include <bits/stdc++.h>
using namespace std;
#define ll long long

constexpr int INF = 1000000000 + 8;

int main() {
    string s, t;
    cin >> s >> t;

    vector<vector<int>> dp(s.size()+1, vector<int>(t.size()+1, INF));
    dp[0][0] = 0;

    for (int i = 0; i < s.size()+1; i++) {
        for (int j = 0; j < t.size()+1; j++) {
            if (i>0 && j>0) {
                if (s[i-1] == t[j-1]) {
                    dp[i][j] = min(dp[i][i], dp[i-1][j-1]);
                } else {
                    dp[i][j] = min(dp[i][j], dp[i-1][j-1] + 1);
                }
            }

            if (j>0) dp[i][j] = min(dp[i][j], dp[i][j-1] + 1);

            if (i>0) dp[i][j] = min(dp[i][j], dp[i-1][j] + 1);
        }
    }

    cout << dp[s.size()][t.size()] << endl;
}