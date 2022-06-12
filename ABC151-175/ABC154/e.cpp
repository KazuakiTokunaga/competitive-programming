#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)

int main() {
    string s; int k;
    cin >> s >> k;
    int size = s.size();

    vector<vector<ll>> dp1(size+1, vector<ll>(k+1, 0)); // Nより小さいことが確定
    vector<vector<ll>> dp2(size+1, vector<ll>(k+1, 0)); // Nより小さいか未確定

    int n = int(s[0]-'0');
    dp1[0][0] = 1;
    dp1[0][1] = n-1;
    dp2[0][1] = 1;

    rep(i, 1, size){
        int n = int(s[i]-'0');
        rep(j, 0, k+1){
            rep(t, 0, 10){
                if (t == 0 and n == 0){
                    dp1[i][j] += dp1[i-1][j];
                    dp2[i][j] += dp2[i-1][j];
                } else if (t == 0 and n > 0){
                    dp1[i][j] += dp1[i-1][j] + dp2[i-1][j];
                    
                } else if (t < n){
                    if (j < 1) continue;
                    dp1[i][j] += dp1[i-1][j-1] + dp2[i-1][j-1];
                } else if (t == n){
                    if (j < 1) continue;
                    dp1[i][j] += dp1[i-1][j-1];
                    dp2[i][j] += dp2[i-1][j-1];
                } else {
                    if (j < 1) continue;
                    dp1[i][j] += dp1[i-1][j-1];
                }
            }
        }
    }

    cout << dp1[size-1][k] + dp2[size-1][k] << endl;
}