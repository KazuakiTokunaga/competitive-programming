#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)

int h, w, a, b, res = 0;
vector<vector<int>> used;

bool dfs(int i, int j, int cur){
    // cout << i << " " << j << " " << cur << endl;
    if (i == (h+1)){
        if (cur == a) {
            // cout << "res++" << endl;
            res++;
        }
        return true;
    }
    if (j == (w+1)) {
        dfs(i+1, 1, cur);
        return true;
    }
    if (used[i][j]) {
        dfs(i, j+1, cur);
        return true;
    }

    if (j+1 <= w and !used[i][j+1]){
        used[i][j] = used[i][j+1] = 1;
        dfs(i, j+1, cur+1);
        used[i][j] = used[i][j+1] = 0;
    }

    if (i+1 <= h and !used[i+1][j]){
        used[i][j] = used[i+1][j] = 1;
        dfs(i, j+1, cur+1);
        used[i][j] = used[i+1][j] = 0;
    }

    dfs(i, j+1, cur);
    return true;
}

int main() {
    cin >> h >> w >> a >> b;
    used.assign(h+1, vector<int>(w+1, 0));

    dfs(1, 1, 0);
    cout << res << endl;
}