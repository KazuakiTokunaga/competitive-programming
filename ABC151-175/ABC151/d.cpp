#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
using Graph = vector<vector<int>>;
const int INF = pow(10,5); 

int get_id(int i, int j, int w){
    return w*i+j;
}

int main() {
    int h,w;
    cin >> h >> w;
    
    vector<string> grid(h);
    rep(i, 0, h){
        string s;
        cin >> s;
        grid[i] = s;
    }

    int m = h*w;
    vector<vector<int>> dp(m, vector<int>(m, INF));
    for (int i = 0; i < m; i++) {
        dp[i][i] = 0;
    }

    rep(i, 0, h){
        rep(j, 0, w){
            if (grid[i][j] == '.'){
                if (i+1 < h and grid[i+1][j] == '.') {
                    dp[get_id(i, j, w)][get_id(i+1, j, w)] = 1;
                    dp[get_id(i+1, j, w)][get_id(i, j, w)] = 1;
                }
                if (j+1 < w and grid[i][j+1] == '.'){
                    dp[get_id(i, j, w)][get_id(i, j+1, w)] = 1;
                    dp[get_id(i, j+1, w)][get_id(i, j, w)] = 1;
                }
            }
        }        
    }

    for (int k = 0; k < m; k++) {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }
    
    // rep(i, 0, m){
    //     cout << i << ": ";
    //     for (auto i: dp[i]) {cout << i << ' ';} cout << endl;
    // }

    int res = 0;
    rep(i, 0, m){
        rep(j, 0, m){
            if (dp[i][j] >= INF) continue;
            else res = max(res, dp[i][j]);
        }
    }
    cout << res << endl;
}