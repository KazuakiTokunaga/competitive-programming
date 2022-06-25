#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define all(x) (x).begin(),(x).end()

int main() {
    int n, t;
    cin >> n >> t;

    vector<pii> dishes;
    rep(i, 0, n){
        int a, b;
        cin >> a >> b;
        dishes.push_back(make_pair(a, b));
    }

    vector<vector<int>> dp1(n+2, vector<int>(t, 0));
    vector<vector<int>> dp2(n+2, vector<int>(t, 0));
    dp1[0][0] = 0;
    rep(i, 1, n+1){
        int a,b;
        tie(a,b) = dishes[i-1];
        rep(j, 0, t){
            dp1[i][j] = dp1[i-1][j];
            if (j-a >=0) dp1[i][j] = max(dp1[i][j], dp1[i-1][j-a]+b);
        }
    }

    dp2[n+1][0] = 0;
    rrep(i, n, 1){
        int a,b;
        tie(a,b) = dishes[i-1];
        rep(j, 0, t){
            dp2[i][j] = dp2[i+1][j];
            if (j-a >= 0) dp2[i][j] = max(dp2[i][j], dp2[i + 1][j - a] + b);
        }
    }

    int res = max(dp1[n][t-1], dp2[1][t-1]);
    rep(i, 0, n){
        rep(j, 0, t){
            res = max(res, dp1[i][j] + dishes[i].second + dp2[i+2][t-1-j]);
        }
    }

    cout << res << endl;
}

// こちらを参考にした
// https://sen-comp.hatenablog.com/entry/2019/11/17/003150