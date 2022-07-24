// ダブリング

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define all(x) (x).begin(),(x).end()

int main() {
    int N; ll K;
    cin >> N >> K;

    vector<int> A(N);
    rep(i, 0, N) {cin >> A[i]; A[i]--;}
    
    // dp[i][j] jから2^i回移動した時の行き先
    vector<vector<int>> dp(62, vector<int>(N, 0));
    rep(i, 0, N){
        dp[0][i] = A[i];
    }

    rep(i, 1, 62){
        rep(j, 0, N){
            dp[i][j] = dp[i-1][dp[i-1][j]];
        }
    }
    
    int idx = 0;
    int city = 0;
    while (K>0){
        if (K & 1) city = dp[idx][city];
        idx++; K = K >> 1;
    }
    cout << city + 1 << endl;
}