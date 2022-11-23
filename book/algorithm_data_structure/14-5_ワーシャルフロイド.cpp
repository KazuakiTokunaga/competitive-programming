// ワーシャル・フロイド法

#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll INF = 1LL << 60;

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<ll>> dp(n, vector<ll>(n, INF));

    for (int e = 0; e < m; e++) {
        int a,b;
        ll w;
        cin >> a >> b >> w;
        dp[a][b] = w;
    }

    for (int v = 0; v < n; v++) {
        dp[v][v] = 0;
    }

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }

    bool exist_negative_cycle = false;
    for (int v = 0; v < n; v++) {
        if (dp[v][v] < 0) exist_negative_cycle = true;
    }
    if (exist_negative_cycle) {
        cout << "NEGATIVE CYCLE" << endl;
    } else {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (j) cout << " ";
                if (dp[i][j] < INF/2) cout << dp[i][j];
                else cout << "INF";
            }
            cout << endl;
        }
    }
}

/*
入力例(図14.1)
6 12
0 1 3
0 3 100
1 3 57
3 1 -5
1 2 50
1 4 -4
2 3 -10
4 3 25
2 4 -5
4 2 57
2 5 100
4 5 8
*/