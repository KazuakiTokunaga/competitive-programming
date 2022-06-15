#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
const ll INF = 1LL << 60;

int main() {
    int h, w, c;
    cin >> h >> w >> c;
    
    vector<vector<ll>> grid(h+1, vector<ll>());
    grid[0] = vector<ll>(w+1, INF);
    rep(i, 1, h+1){
        grid[i].push_back(INF);
        rep(j, 1, w+1){
            ll a;
            cin >> a;
            grid[i].push_back(a);
        }
    }

    ll res = INF;
    vector<vector<ll>> dp(h+1, vector<ll>(w+1, INF));
    rep(i, 1, h+1){
        rep(j, 1, w+1){
            ll smaller = min(dp[i-1][j], dp[i][j-1]);
            ll cost = smaller + grid[i][j] + c;
            res = min(res, cost);

            dp[i][j] = min(smaller + c, (ll)grid[i][j]);
        }
    }

    reverse(grid.begin()+1, grid.end());
    vector<vector<ll>> dp1(h+1, vector<ll>(w+1, INF));
    rep(i, 1, h+1){
        rep(j, 1, w+1){
            ll smaller = min(dp1[i-1][j], dp1[i][j-1]);
            ll cost = smaller + grid[i][j] + c;
            res = min(res, cost);

            dp1[i][j] = min(smaller + c, (ll)grid[i][j]);
        }
    }

    cout << res << endl;
}