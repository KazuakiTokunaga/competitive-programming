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
    
    vector<string> grid;
    rep(i, 0, H){
        string s;
        cin >> s;
        grid.push_back(s);
    }

    vector<pii> pin;
    rep(i, 0, H){
        rep(j, 0, W){
            if (grid[i][j] == 'o') pin.push_back({i, j});
        }
    }

    cout << abs(pin[0].first - pin[1].first) + abs(pin[0].second - pin[1].second) << endl;
}