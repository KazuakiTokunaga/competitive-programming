#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define all(x) (x).begin(),(x).end()
const ll INF = 2LL << 60;

int main() {
    int N;
    cin >> N;
    
    vector<int> A(N);
    rep(i, 0, N) cin >> A[i];
    
    ll res = INF;

    // dp[i][0]: i枚目まで埋まっていて、i+1は未使用
    // dp[i][1]: i枚目まで埋まっていて、i+1も埋まっている
    vector<vector<ll>> dp(N, vector<ll>(2, INF));
    
    // A[0]を使用する場合
    dp[0][1] = A[0];
    rep(i, 1, N){
        
        // 1枚目を使う
        dp[i][1] = min(dp[i-1][0], dp[i-1][1]) + A[i];

        // 1枚目を使わない
        dp[i][0] = dp[i-1][1];
    }

    res = min(dp[N-1][0], dp[N-1][1]);

    // A[0]を使用せずにA[N-1]を使用する場合
    dp.assign(N, vector<ll>(2, INF));
    dp[0][0] = A[N-1];
    rep(i, 1, N-1){
        dp[i][1] = min(dp[i-1][0], dp[i-1][1]) + A[i];
        dp[i][0] = dp[i-1][1];
    }

    res = min(min(res, dp[N-2][0]), dp[N-2][1]);
    cout << res << endl;
}