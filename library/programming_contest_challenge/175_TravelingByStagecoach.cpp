// ビットDP
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define all(x) (x).begin(),(x).end()
const int INF = pow(10, 9) + 7;

int main() {
    int n, m, a, b, p; // pは辺の数
    cin >> n >> m >> a >> b >> p;

    vector<int> t(n);
    rep(i, 0, n) cin >> t[i];

    vector<vector<int>> d(m, vector<int>(m, -1));
    rep(i, 0, p){
        int pa, pb, pc;
        cin >> pa >> pb >> pc; pa--; pb--;
        d[pa][pb] = pc;
        d[pb][pa] = pc;
    }

    vector<vector<double>> dp(m, vector<double>(m, INF));
    dp[(1<<n)-1][a-1] = 0;
    double res = INF;

    // だんだん乗車券を使ってグラフの下に降りていく
    // ただしb-1につくときに乗車券を全消費していくとは限らない
    rrep(S, (1<<n)-1, 0){
        res = min(res, dp[S][b-1]);
        rep(v, 0, m){
            rep(i, 0, n){ // v -> uの遷移で乗車券iを使う
                if (S >> i & 1){ // この時点で乗車券iが残っているかどうか
                    rep(u, 0, m){
                        if(d[v][u] >= 0){
                            dp[S & ~(1 << i)][u] = min(dp[S& ~ (1<<i)][u], dp[S][v] + (double)d[v][u] / t[i]);
                        }
                    }
                }
            }
        }
    }

    if (res == INF) cout << "Impossible" << endl;
    else cout << res << endl;
}

/*
2 4 2 1 4
3 1
1 4 2
1 3 3
2 4 5
2 3 3
*/
