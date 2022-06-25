#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define all(x) (x).begin(),(x).end()
const int INF = pow(10, 9) + 7;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> A(m, 0), B(m, 0), C(m, 0);
    rep(i, 0, m){
        int a, b;
        cin >> a >> b;
        A[i] = a; B[i] = b;

        int c = 0;
        rep(j, 0, b){
            int c1; cin >> c1;
            c1 = (1 << (c1-1));
            c |= c1;
        }
        C[i] = c;
    }

    // dp[i][j] = i番目の箱までをみたときに状態jを実現する最小コスト
    vector<vector<int>> dp(m+1, vector<int>(1 << (n+1), INF));
    dp[0][0] = 0;
    rep(i, 1, m+1){
        int c = C[i-1];
        rep(j, 0, pow(2, n)){
            int nxt = j | c;
            dp[i][j] = min(dp[i][j], dp[i-1][j]);
            dp[i][nxt] = min(dp[i][nxt], dp[i-1][j] + A[i-1]);
        }
    }

    // cout << "dp[1]: ";
    // for (auto i: dp[1]) {cout << i << ' ';} cout << endl;
    
    if (dp[m][pow(2, n)-1] == INF) cout << -1 << endl;
    else cout << dp[m][pow(2, n) - 1] << endl;
}