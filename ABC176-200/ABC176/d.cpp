#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
typedef tuple<int, int, int> cell;

int h, w, ch, cw, dh, dw;
vector<vector<int>> seen;
vector<string> grid;
vector<pii> warp = {{-2, -2}, {-2, -1}, {-2, 0}, {-2, 1}, {-2, 2}, {-1, -2}, {-1, -1}, {-1, 1}, {-1, 2},
    {0, -2}, {0, 2}, {1, -2}, {1, -1}, {1, 1}, {1, 2}, {2, -2}, {2, -1}, {2, 0}, {2, 1}, {2, 2}};

bool check(int i, int j){
    if (i < 0 or i >= h or j < 0 or j >= w) return false;
    if (grid[i][j] == '.') return true;
    else return false;
}

bool bfs(auto &q, int i, int j, int cnt){
    if (seen[i][j] > cnt) seen[i][j] = cnt;
    else return true;

    if (check(i+1, j)) q.push({i+1, j, cnt});
    if (check(i-1, j)) q.push({i-1, j, cnt});
    if (check(i, j+1)) q.push({i, j+1, cnt});
    if (check(i, j-1)) q.push({i, j-1, cnt});

    for (auto p: warp) {
        int next_i = i+p.first;
        int next_j = j+p.second;
        if (check(next_i, next_j)) q.push({next_i, next_j, cnt+1});
    }

    while(!q.empty()){
        cell c = q.top(); q.pop();
        int next_i = get<0>(c), next_j = get<1>(c), next_cnt = get<2>(c);
        bfs(q, next_i, next_j, next_cnt);
    }

    return true;
}

int main() {
    cin >> h >> w >> ch >> cw >> dh >> dw;
    rep(i, 0, h){
        string s;
        cin >> s;
        grid.push_back(s);
    }
    seen.assign(h, vector<int>(w, pow(10, 6)));

    auto c = [](cell l, cell r) { return get<2>(l) >= get<2>(r);};
    priority_queue<cell, vector<cell>, decltype(c)> q(c);

    bfs(q, ch-1, cw-1, 0);
    if (seen[dh-1][dw-1] == pow(10, 6)) cout << -1 << endl;
    else cout << seen[dh-1][dw-1] << endl;
}