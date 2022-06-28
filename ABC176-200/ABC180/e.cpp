#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define all(x) (x).begin(),(x).end()
const int INF = pow(10, 9) + 7;
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return true; } return false;}

int main() {
    int N;
    cin >> N;

    vector<vector<int>> Cities(N, vector<int>());
    rep(i, 0, N){
        int x, y, z;
        cin >> x >> y >> z;
        Cities[i] = {x, y, z};
    }

    vector<vector<int>> graph(N, vector<int>(N, INF));
    rep(i, 0, N){
        rep(j, 0, N){
            int a = Cities[i][0], b = Cities[i][1], c = Cities[i][2];
            int p = Cities[j][0], q = Cities[j][1], r = Cities[j][2];

            graph[i][j] = abs(p-a) + abs(q-b) + max(0, r-c);
            graph[j][i] = abs(a-p) + abs(b-q) + max(0, c-r);
        }
    }

    vector<vector<int>> dp((1 << N), vector<int>(N, INF));
    dp[(1<<N)-1][0] = 0;
    rrep(bit, ((1<<N) - 1), 0){
        rep(i, 0, N){
            rep(j, 0, N){
                if (i == j) continue;
                // if (!((bit >> j) & 1)) continue;
                // cout << bit << " " << i << " " << j << " " << graph[i][j] << endl;
                chmin(dp[bit ^ (1 << j)][j], dp[bit][i] + graph[i][j]);
            }
        }
    }

    // rrep(j, dp.size()-1, 0){
    //     for (auto i: dp[j]) {cout << i << ' ';} cout << endl;
    // }
    cout << dp[0][0] << endl;
}