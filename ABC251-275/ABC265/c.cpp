#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define all(x) (x).begin(),(x).end()

int main() {
    int H, W;
    cin >> H >> W;

    vector<string> grid(H);
    rep(i, 0, H) cin >> grid[i];

    vector<vector<int>> used(H, vector<int>(W, 0));

    int h = 0, w = 0;
    while (true){
        if (used[h][w] == 1){
            cout << -1 << endl;
            return 0;
        }

        used[h][w] = 1;
        char dir = grid[h][w];

        int h1 = h, w1 = w;
        if (dir == 'U') h1--;
        if (dir == 'D') h1++;
        if (dir == 'L') w1--;
        if (dir == 'R') w1++;

        if (h1 < 0 or h1 >= H or w1 < 0 or w1 >= W){
            cout << h+1 << " " << w+1 << endl;
            return 0;
        }

        h = h1;
        w = w1;
    }
}