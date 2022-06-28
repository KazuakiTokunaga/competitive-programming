#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define all(x) (x).begin(),(x).end()
const int INF = pow(10, 9) + 7;

int N, M;
vector<int> A, B;
vector<vector<int>> dp;

int dfs(int i, int j){
    if (dp[i][j] < INF) return dp[i][j];

    // cout << "new call: " << i << " " << j << endl;
    // A側はなくなったけどB側は余っている
    if (i == N){
        // cout << i << " " << j << " " << M - j << endl;
        return dp[i][j] = M - j;
    }

    // B側はなくなったけどA側は余っている
    if (j == M){
        // cout << i << " " << j << " " << N - i << endl;
        return dp[i][j] = N - i;
    }

    // 一致しているとき
    if (A[i] == B[j]){
        int a = dfs(i+1, j+1); // マッチさせる
        int b = dfs(i+1, j) + 1;
        int c = dfs(i, j+1) + 1;
        return dp[i][j] = min(min(a,b), c);
    
    // 一致していないとき
    } else {
        int a = dfs(i+1, j+1) + 1; // マッチさせる
        int b = dfs(i+1, j) + 1;
        int c = dfs(i, j+1) + 1;
        return dp[i][j] = min(min(a, b), c);
    }
}


int main() {
    cin >> N >> M;
    
    A.assign(N, 0); B.assign(M, 0);
    rep(i, 0, N) cin >> A[i];
    rep(i, 0, M) cin >> B[i];

    // dp[i][j] Aをi文字、Bをj文字まで捨てるかマッチさせたときの、x+yの最小値
    dp.assign(N+1, vector<int>(M+1, INF));
    dp[N][M] = 0;

    dfs(0, 0);            

    // rep(i, 0, N+1){
    //     for (auto j: dp[i]) {cout << j << ' ';} cout << endl;
    // }
    cout << dp[0][0] << endl;
}