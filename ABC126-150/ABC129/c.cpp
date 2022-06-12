#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
const int MOD = pow(10,9) + 7;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> a(m+1);
    for (int i = 0; i < m; i++) cin >> a[i];

    vector<int> dp(n+3);

    
    int index = 0;
    dp[0] = 0;
    dp[1] = 1;

    rep(i, 2, n+2){
        if ((i-1) == a[index]) {dp[i] = 0; index++;}
        else dp[i] = (dp[i-1] + dp[i-2]) % MOD;
    }

    cout << dp[n+1] << endl;
}