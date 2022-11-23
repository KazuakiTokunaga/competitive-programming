#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define all(x) (x).begin(),(x).end()
const ll INF = 2LL << 60;

int main() {
    int N, M;
    cin >> N >> M;
    
    vector<ll> A(N);
    rep(i, 0, N) cin >> A[i];

    // dp[i][j]; A[i]までみてj番目まで与えているときの最大値
    vector<vector<ll>> dp(2010, vector<ll>(2010, -1 * INF));

    dp[0][1] = A[0];
    rep(i, 1, N){
        dp[i][1] = max(dp[i-1][1], A[i]);
        rep(j, 2, M+1){
            if (dp[i-1][j-1] > -1 * INF) dp[i][j] = max(dp[i-1][j], dp[i-1][j-1]+ j*A[i]);
        }
    }

    cout << dp[N-1][M] << endl;
}