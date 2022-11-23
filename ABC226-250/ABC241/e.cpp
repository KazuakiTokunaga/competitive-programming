#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define all(x) (x).begin(),(x).end()

int main() {
    ll N, K;
    cin >> N >> K;
    
    vector<int> A(N);
    rep(i, 0, N) cin >> A[i];
    
    // dp[i][j]: jからスタートして2^i回後に何個増えるか
    vector<vector<ll>> dp(50, vector<ll>(N, 0));
    rep(i, 0, N) {
        dp[0][i] = A[i]; 
    }

    rep(i, 1, 50){
        rep(j, 0, N){
            dp[i][j] = dp[i-1][j] + dp[i-1][(j + dp[i-1][j]) % N];
        }
    }

    ll res = 0;
    rep(i, 0, 50){
        if (K & (1LL << i)) {
            res += dp[i][res % N];
        }
    }

    cout << res << endl;
}