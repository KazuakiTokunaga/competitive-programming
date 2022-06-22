// 蟻本のソースコードは難しいので、こちらを参照（pp. 18~）
// https://www.slideshare.net/hcpc_hokudai/advanced-dp-2016

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

    vector<string> grid;
    rep(i, 0, n){
        string s;
        cin >> s;
        grid.push_back(s);
    }

    vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(m+1, vector<int>(1<<m, 0)));
    dp[0][0][0] = 1;
    rep(i, 0, n){
        rep(j, 0, m){
            rep(used, 0, 1<<m){
                if (used & (1 << j) or grid[i][j] == 'x') {
                    int next = used & ~(1 << j);
                    if (j+1 < m) {dp[i][j+1][next] += dp[i][j][used]; dp[i][j+1][next] %= MOD;}
                    else {dp[i+1][0][next] += dp[i][j][used]; dp[i+1][0][next] %= MOD;}
                } else {
                    // 横置き
                    if (j+1 < m and !(grid[i][j+1]=='x') and !(used & (1<<(j+1)))){
                        int next = used | (1 << (j+1));
                        dp[i][j+1][next] += dp[i][j][used];
                        dp[i][j+1][next] %= MOD;
                    }
                    // 縦置き
                    if (i+1 < n and !(grid[i+1][j]=='x')){
                        int next = used | (1<<j);
                        if (j+1 < m) {dp[i][j+1][next] += dp[i][j][used]; dp[i][j+1][next] %= MOD;}
                        else {dp[i+1][0][next] += dp[i][j][used];dp[i+1][0][next] %= MOD;}
                    }
                }
            }
        }
    }

    // 1<<(m-1)は、現在位置が(n-1,m-1)として(n-1,m-1)だけが使われている状態（その他の場所は行溢れなので全て使用していない）
    cout << dp[n-1][m-1][1<<(m-1)] << endl; 
}

/*
3 3
...
.x.
...

6 6
......
..xx..
......
....xx
......
xx....
336
*/