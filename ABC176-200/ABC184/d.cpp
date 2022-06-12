#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)

int main() {
    int a,b,c;
    cin >> a >> b >> c;
    
    vector<vector<vector<ld>>> dp(101, vector<vector<ld>>(101, vector<ld>(101, 0)));
    dp[99][99][99] = 1;
    rrep(i, 98, 0){
        ld prob = ((ld)i / (99+99+i));
        dp[i][99][99] = prob * (1 + dp[i+1][99][99]) + (1 - prob) * 1;
    }

    rrep(j, 98, 0){
        rrep(i, 99, 0){
            ld prob_a = ((ld)i / (i + j + 99));
            ld prob_b = ((ld)j / (i + j + 99));
            dp[i][j][99] = prob_a * (1 + dp[i+1][j][99]) + prob_b * (1 + dp[i][j+1][99]) + (1 - prob_a - prob_b) * 1;
        }
    }

    rrep(k, 98, 0){
        rrep(j, 99, 0){
            rrep(i, 99, 0){
                if (i == k and i == j and i == 0) continue;
                ld prob_a = ((ld)i / (i + j + k));
                ld prob_b = ((ld)j / (i + j + k));
                dp[i][j][k] = prob_a * (1 + dp[i+1][j][k]) + prob_b * (1 + dp[i][j+1][k]) 
                    + (1 - prob_a - prob_b) * (1 + dp[i][j][k+1]);
            }
        }
    }
    
    cout << fixed << setprecision(15);
    cout << dp[a][b][c] << endl;

}