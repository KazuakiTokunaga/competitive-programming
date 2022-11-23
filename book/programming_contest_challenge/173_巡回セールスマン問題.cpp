// ビットDP
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define all(x) (x).begin(),(x).end()
const int INF = pow(10, 9) + 7;

int n, m;
vector<vector<int>> d;
vector<vector<int>> dp;

int rec(int S, int v){
    if (dp[S][v] >= 0) return dp[S][v];
    if (S == (1 << n) - 1 && v == 0) return dp[S][v] = 0;

    int res = INF;
    rep(u, 0, n){
        if (!(S >> u & 1)){
            res = min(res, rec(S | 1 << u, u) + d[v][u]);
        }
    }
    return dp[S][v] = res;
}

int main() {
    cin >> n >> m; // mは辺の本数
    dp.assign(1 << n, vector<int>(n, -1));
    d.assign(n, vector<int>(n, INF)); // 距離

    rep(i, 0, m){
        int a, b, c;
        cin >> a >> b >> c;
        d[a][b] = c;
    }
    
    cout << rec(0, 0) << endl;
}

/*
5 8
0 1 3
1 2 5
2 3 5
3 4 3
4 0 7
4 1 6
0 3 4
2 0 4
*/