#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)

int main(){
    int h, w;
    cin >> h >> w;

    vector<string> grid;
    rep(i, 0, h){
        string s;
        cin >> s;
        grid.push_back(s);
    }

    int res = 0;
    rep(i, 0, h-1){
        rep(j, 0, w-1){
            int cnt = 0;
            if (grid[i][j] == '#') cnt++;
            if (grid[i+1][j] == '#') cnt++;
            if (grid[i][j+1] == '#') cnt++;
            if (grid[i+1][j+1] == '#') cnt++;
            if (cnt % 2 == 1) res++;
        }
    }

    cout << res << endl;
}