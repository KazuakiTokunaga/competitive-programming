#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define all(x) (x).begin(),(x).end()
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false;}

int main() {
    int N, M;
    cin >> N >> M;
    
    vector<int> X(N);
    rep(i, 0, N) cin >> X[i];
    
    vector<int> bonus(5100, 0);
    rep(i, 0, M){
        int C, Y;
        cin >> C >> Y;
        bonus[C] = Y;
    }

    // dp[i][j]: i番目の数までみていて、カウンタがjのときの最大値
    vector<vector<ll>> dp(N+1, vector<ll>(N+1, -1));
    dp[0][0] = 0;
    rep(i, 1, N+1){
        rep(j, 0, N){
            if (dp[i-1][j] == -1) continue;

            if (j+1 < N+1) chmax(dp[i][j+1], dp[i-1][j] + bonus[j+1] + X[i-1]);
            chmax(dp[i][0], dp[i-1][j]);
        }
    }
    
    ll res = 0;
    rep(i, 0, N+1){
        chmax(res, dp[N][i]);
    }
    cout << res << endl;
}