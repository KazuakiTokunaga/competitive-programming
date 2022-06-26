// 想定解法（DP）

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define all(x) (x).begin(),(x).end()
const int INF = pow(10, 9) + 7;

template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return true; } return false;}

int main() {
    string s;
    cin >> s;
    int n = s.size();
    
    vector<int> digits;
    reverse(all(s));
    rep(i, 0, n){
        int d = (int)(s[i]-'0');
        digits.push_back(d);
    }

    vector<vector<int>> dp(n+1, vector<int>(2, INF));
    dp[0][0] = 0;
    rep(i, 0, n){
        rep(d, 0, 2){
            if (dp[i][d] != INF){
                int c = digits[i] + d;
                if (c != 10) chmin(dp[i+1][0], dp[i][d] + c);
                chmin(dp[i+1][1], dp[i][d]+10-c);
            }
        }
    }

    int ans = min(dp[n][0], dp[n][1] + 1);
    cout << ans << endl;
}