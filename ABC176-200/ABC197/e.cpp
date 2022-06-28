#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define all(x) (x).begin(),(x).end()
const ll INF = 1LL << 60;

int main() {
    int N;
    cin >> N;

    vector<vector<int>> Balls(N+2, vector<int>());
    rep(i, 0, N){
        int x, c;
        cin >> x >> c;
        Balls[c].push_back(x);
    }
    Balls[N+1] = {0}; // 最後にNに戻ってくる
    rep(i, 0, N+2) sort(all(Balls[i]));
    
    // Edge[i][0]; 色iの右端、Edge[i][1]; 色iの左端
    vector<vector<int>> Edge(N+2, vector<int>(2, 0));
    rep(i, 0, N+1){
        if (!Balls[i].empty()){
            Edge[i][0] = Balls[i].back();
            Edge[i][1] = Balls[i].front();
        }
    }

    // dp[i][0] 色iを回収し終えたとき最も右にいたときの、時間の最小値
    vector<vector<ll>> dp(N+2, vector<ll>(2, INF));
    dp[0][0] = dp[0][1] = 0;

    rep(i, 1, N+2){
        vector<int> Ball = Balls[i];
        if (Ball.empty()) {
            dp[i][1] = dp[i-1][1];
            dp[i][0] = dp[i-1][0];
            Edge[i][0] = Edge[i-1][0];
            Edge[i][1] = Edge[i-1][1];
            continue;
        }

        int b = Ball.back(), a = Ball.front();
        rep(j, 0, 2){
            ll t = dp[i-1][j];
            int x = Edge[i-1][j];

            // 左に行って右に止まる
            if (a < x){
                dp[i][0] = min(dp[i][0], t + (x - a) + (b - a));
            } else {
                dp[i][0] = min(dp[i][0], t + (b - x));
            }

            // 右に行って左に止まる
            if (x < b){
                dp[i][1] = min(dp[i][1], t + (b - x) + (b - a));
            } else {
                dp[i][1] = min(dp[i][1], t + (x - a));
            }
        }
    }

    cout << dp[N+1][0] << endl;
}