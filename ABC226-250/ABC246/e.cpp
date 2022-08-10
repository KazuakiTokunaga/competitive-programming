#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using ppi = pair<pii, int>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define all(x) (x).begin(),(x).end()
const int INF = pow(10, 9) + 7;
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return true; } return false;}

int main() {
    int N;
    cin >> N;
    
    int Ax, Ay, Bx, By;
    cin >> Ax >> Ay >> Bx >> By;
    Ax--; Ay--; Bx--; By--;

    vector<string> grid;
    rep(i, 0, N){
        string s;
        cin >> s;
        grid.push_back(s);
    }

    vector<vector<vector<int>>> dist(N, vector<vector<int>>(N, vector<int>(4, INF)));
    vector<pii> dir_map = {{1, 1}, {-1, -1}, {1, -1}, {-1, 1}};
    deque<ppi> q;
    rep(i, 0, 4){
        dist[Ax][Ay][i] = 1;   
        q.push_back({{Ax, Ay}, i});     
    };

    
    while (!q.empty()){
        ppi pp = q.front(); q.pop_front();
        pii cord = pp.first;
        
        rep(i, 0, 4){
            int add = 1;
            if (i == pp.second) add = 0;

            pii dir = dir_map[i];

            int nxt_h = cord.first + dir.first;
            int nxt_w = cord.second + dir.second;
            if (nxt_h >= N or nxt_w >= N or nxt_h < 0 or nxt_w < 0) continue;
            if (grid[nxt_h][nxt_w] == '#') continue;

            if (chmin(dist[nxt_h][nxt_w][i], dist[cord.first][cord.second][pp.second] + add)) {
                if (!add) q.push_front({{nxt_h, nxt_w}, i});
                else q.push_back({{nxt_h, nxt_w}, i});
            }
        }
    }

    int res = INF;
    rep(i, 0, 4){
        if (dist[Bx][By][i] != INF) res = min(dist[Bx][By][i], res);
    }
    if (res == INF) cout << -1 << endl;
    else  cout << res << endl;
}