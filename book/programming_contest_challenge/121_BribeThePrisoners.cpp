#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define all(x) (x).begin(),(x).end()

int main() {
    int p, q;
    cin >> p >> q;

    vector<int> a(q+2);
    a[0] = 0, a[q+1] = p+1;
    rep(i, 1, q+1) cin >> a[i];

    vector<vector<int>> dp(q+1, vector<int>(q+2, pow(10, 9)+7));
    rep(i, 0, q+1){
        dp[i][i+1] = 0;
    }
    
    rep(w, 2, q+2){
        rep(i, 0, q-w+2){
            int j = i+w, t = pow(10, 9)+7;
            rep(k, i+1, j){
                t = min(t, dp[i][k] + dp[k][j]);
            }

            dp[i][j] = t + a[j] - a[i] - 2;
        }
    }

    cout << dp[0][q+1] << endl;
}

/*
20 3
3 6 14
*/