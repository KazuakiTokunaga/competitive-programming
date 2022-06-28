#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define all(x) (x).begin(),(x).end()
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return true; } return false;}
const int INF = pow(10, 9) + 7;

int main() {
    int H, W;
    cin >> H >> W;

    vector<string> grid;
    rep(i, 0, H){
        string s; cin >> s;
        grid.push_back(s);
    }

    vector<vector<int>> d(H, vector<int>(W, INF));
    vector<vector<pii>> Warp(26);
    vector<int> used(26, 0);
    queue<pii> q;
    pii Goal;
    rep(i, 0, H){
        rep(j, 0, W){
            if (grid[i][j] == 'S'){
                q.push({i, j});
                d[i][j] = 0;
            } else if (grid[i][j] == 'G'){
                Goal = {i, j};
            } else if (isalpha(grid[i][j])){
                int idx = grid[i][j] - 'a';
                Warp[idx].push_back({i, j});
            }
        }
    }
    
    while (!q.empty()){
        pii p = q.front(); q.pop();
        
        int h, w;
        tie(h, w) = p;
        char c = grid[h][w];

        vector<pii> DHDW = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        for (pii dhdw : DHDW) {
            int dh = dhdw.first + h;
            int dw = dhdw.second + w;
            if (0 <= dh and dh < H and 0 <= dw and dw < W and grid[dh][dw] != '#'){
                if (chmin(d[dh][dw], d[h][w]+1)){
                    q.push({dh, dw});
                }
            }
        }

        if (c != 'S' and c != 'G' and isalpha(c)){
            int idx = c - 'a';
            if (used[idx]) continue;
            for (pii to: Warp[idx]) {
                // 自分自身はスキップ
                if (to == p) continue;

                int dh, dw;
                tie(dh, dw) = to;
                if (chmin(d[dh][dw], d[h][w]+1)){
                    q.push({dh, dw});
                }
            }
            used[idx] = true;
        }

    }


    int a, b;
    tie(a, b) = Goal;
    int res = d[a][b];
    cout << (res != INF ? res: -1) << endl;
}