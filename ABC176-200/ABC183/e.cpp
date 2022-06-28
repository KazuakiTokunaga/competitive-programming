#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define all(x) (x).begin(),(x).end()
const int MOD = pow(10, 9) + 7;

int main() {
    int H, W;
    cin >> H >> W;

    vector<string> grid;
    
    rep(i, 0, H){
        string s;
        cin >> s;
        grid.push_back(s);
    }

    vector<ll> Hs(H, 0);
    vector<ll> Ws(W, 0);
    vector<ll> Cross(H+W+100, 0);

    

    vector<vector<ll>> dp(H, vector<ll>(W, 0));
    rep(i, 0, H){
        rep(j, 0, W){
            if (grid[i][j] == '#'){
                dp[i][j] = 0;
                Hs[i] = Ws[j] = Cross[j-i+H] = 0;
            } else {
                dp[i][j] = Hs[i] + Ws[j] + Cross[j-i+H];
                dp[i][j] %= MOD;
                if (i == 0 and j == 0) dp[i][j] = 1;
                
                Hs[i] += dp[i][j]; Hs[i] %= MOD;
                Ws[j] += dp[i][j]; Ws[j] %= MOD;
                Cross[j-i+H] += dp[i][j]; Cross[j-i+H] %= MOD;
            }
        }
    }

    cout << dp[H-1][W-1] << endl;
}