// 整数nを分割の順番は区別せずにm分割する場合の和。O(nm)

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define all(x) (x).begin(),(x).end()
const int MOD = pow(10, 9) + 7;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

    dp[0][0] = 1;
    rep(i, 1, m+1){
        rep(j, 0, n+1){
            if (j-i >= 0){
                dp[i][j] = dp[i-1][j] + dp[i][j-i];
                dp[i][j] %= MOD;
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    
    for (auto i: dp[1]) {cout << i << ' ';} cout << endl;
    

    cout << dp[m][n] << endl;
}

/*
4 3

100 10
*/