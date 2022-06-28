#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define all(x) (x).begin(),(x).end()
const int INF = pow(10,9) + 7;

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> A(N);
    rep(i, 0, N) cin >> A[i];

    vector<vector<int>> graph(N, vector<int>());
    rep(i, 0, M){
        int x, y;
        cin >> x >> y; x--; y--;
        graph[x].push_back(y);
    }

    // dp[i] iに到達したときに入手しうる金の最安値
    vector<int> dp(N, INF);
    int res = -INF;
    rep(i, 0, N){

        // その街で金を売った場合の利益
        if (dp[i] != INF) res = max(res, A[i] - dp[i]);
    
        dp[i] = min(dp[i], A[i]);
        for (int e: graph[i]) {
            dp[e] = min(dp[e], dp[i]);
        }
    
    }

    cout << res << endl;
}