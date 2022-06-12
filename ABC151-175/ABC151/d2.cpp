#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
using Graph = vector<vector<int>>;
int h,w;


bool bfs(vector<string> &grid, vector<vector<int>> &distance, queue<pair<int, int>> &search, int i, int j){
    if (grid[i][j] != '.') return true;

    if (i+1 < h and distance[i+1][j] == -1 and grid[i+1][j] == '.') {
        distance[i+1][j] = distance[i][j] + 1;
        search.push(make_pair(i+1, j));
    }
    if (i-1 >= 0 and distance[i-1][j] == -1 and grid[i-1][j] == '.') {
        distance[i-1][j] = distance[i][j] + 1;
        search.push(make_pair(i-1, j));
    }
    if (j+1 < w and distance[i][j+1] == -1 and grid[i][j+1] == '.'){
        distance[i][j+1] = distance[i][j] + 1;
        search.push(make_pair(i, j+1));
    }
    if (j-1 >= 0 and distance[i][j-1] == -1 and grid[i][j-1] == '.'){
        distance[i][j-1] = distance[i][j] + 1;
        search.push(make_pair(i, j-1));
    }

    while (!search.empty()){
        auto p = search.front();
        search.pop();
        bfs(grid, distance, search, p.first, p.second);
    }

    return true;
}

int main() {

    cin >> h >> w;
    
    vector<string> grid(h);
    rep(i, 0, h){
        string s;
        cin >> s;
        grid[i] = s;
    }

    int res = 0;
    rep(i, 0, h){
        rep(j, 0, w){
            vector<vector<int>> distance(h, vector<int>(w, -1));
            queue<pair<int, int>> search;
            distance[i][j] = 0;
            bfs(grid, distance, search, i, j);

            rep(k, 0, h){
                rep(l, 0, w){
                    res = max(distance[k][l], res);
                }
            }

        }
    }

    cout << res << endl;
}