#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define all(x) (x).begin(),(x).end()

int main() {
    int N, X;
    cin >> N >> X;
    
    vector<vector<int>> dp(N+1, vector<int>(10010, 0));
    dp[0][0] = 1;
    rep(i, 1, N+1) {
        int a, b;
        cin >> a >> b;

        rep(j, 0, 10010){
            dp[i][j+a] += dp[i-1][j];
            dp[i][j+b] += dp[i-1][j];
        }
    }

    if (dp[N][X]) cout << "Yes" << endl;
    else cout << "No" << endl;

}