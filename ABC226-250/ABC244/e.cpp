#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define all(x) (x).begin(),(x).end()
const int MOD = 998244353;

int N, M, K, S, T, X;
vector<vector<int>> graph;
ll res = 0;

int main() {

    cin >> N >> M >> K >> S >> T >> X;
    S--; T--; X--;

    graph.assign(N, vector<int>());
    rep(i, 0, M){
        int u, v;
        cin >> u >> v; u--; v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    // dp[i][j][k]; i回移動後にjにいてXへの到達が偶数回/奇数回である場合
    vector<vector<vector<int>>> dp(K+1, vector<vector<int>>(N, vector<int>(2, 0)));
    dp[0][S][0] = 1;
    rep(i, 0, K){
        rep(j, 0, N){
            rep(k, 0, 2){
                for (int nxt: graph[j]) {
                    int nxt_k = k;
                    if (nxt == X) nxt_k = 1 - k;
                    dp[i+1][nxt][nxt_k] += dp[i][j][k];
                    dp[i+1][nxt][nxt_k] %= MOD;
                    // if (dp[i+1][nxt][nxt_k] > 0){
                    //     cout << i+1 << " " << nxt << " " << nxt_k << ": " << dp[i+1][nxt][nxt_k] << endl;
                    // }
                }
            }
        }
    }

    cout << dp[K][T][0] << endl;
}