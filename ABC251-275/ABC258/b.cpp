#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define all(x) (x).begin(),(x).end()

int main() {
    int N;
    cin >> N;
    
    vector<string> grid;
    rep(i, 0, N){
        string s;
        cin >> s;
        grid.push_back(s);
    }

    vector<pii> dxdy = {{1,1},{1,0},{1,-1},{0,1},{0,-1},{-1,1},{-1,0},{-1,-1}};
    string res = "";
    rep(i, 0, N){
        rep(j, 0, N){
            for (pii dir: dxdy) {
                int cy = i, cx = j;
                string s = string() + grid[cy][cx];

                int dx, dy;
                tie(dy, dx) = dir;
                rep(k, 0, N-1){
                    cy += dy, cx += dx;
                    cy %= N, cx %= N;
                    if (cy < 0) cy += N;
                    if (cx < 0) cx += N;

                    s += grid[cy][cx];

                }

                res = max(res,s);
            }
        }
    }
    cout << res << endl;
}