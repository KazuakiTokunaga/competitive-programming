#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)

int h, w;
vector<vector<pii>> dp;
vector<string> grid;

int point(int i, int j){
    if (grid[i][j] == '+') return 1;
    else return -1;
}

int main() {
    cin >> h >> w;
    dp.assign(h, vector<pii>(w, make_pair(0,0)));

    rep(i, 0, h){
        string s;
        cin >> s;
        grid.push_back(s);
    }

    if ((h-1 + w-1) % 2 == 0) dp[h-1][w-1] = {0, point(h-1, w-1)};
    else dp[h-1][w-1] = {point(h-1, w-1), 0};

    rrep(i, w-2, 0){
        int a, b;
        tie(a,b) = dp[h-1][i+1];
        if ((h-1 + i) % 2 == 0){
            dp[h-1][i] = {a, b + point(h-1, i)};
        } else {
            dp[h-1][i] = {a + point(h-1, i), b};
        }
    }

    rrep(i, h-2, 0){
        int a, b;
        tie(a,b) = dp[i+1][w-1];
        if ((w-1 + i) % 2 == 0){
            dp[i][w-1] = {a, b + point(i, w-1)};
        } else {
            dp[i][w-1] = {a + point(i, w-1), b};
        }
    }

    rrep(i, h-2, 0){
        rrep(j, w-2, 0){
            int a,b, c, d;
            tie(a,b) = dp[i+1][j]; // 下
            tie(c,d) = dp[i][j+1]; // 右

            if ((i + j) % 2 == 1){
                if ((b-a) > (d-c)) dp[i][j] = {a + point(i, j), b};
                else dp[i][j] = {c + point(i, j), d};
            } else {
                if ((a-b) > (c-d)) dp[i][j] = {a, b + point(i, j)};
                else dp[i][j] = {c, d + point(i, j)};
            }
        }
    }

    int a,b;
    tie(a,b) = dp[0][0];
    b -= point(0, 0);
    if (a > b) cout << "Takahashi" << endl;
    else if (a == b) cout << "Draw" << endl;
    else cout << "Aoki" << endl;

    // rep(i, 0, h){
    //     for (auto i: dp[i]) {cout << i.first << ";" << i.second << ' ';} cout << endl;   
    // }
}