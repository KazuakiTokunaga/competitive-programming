#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)

int main() {
    int h, w, k;
    cin >> h >> w >> k;
    
    vector<string> grid;
    rep(i, 0, h){
        string s;
        cin >> s;
        grid.push_back(s);
    }

    // 2^N通りの部分集合全体を走査
    int res = 0;
    for (int bit=0; bit < (1 << h); bit++){
        for (int bit1 = 0; bit1 < (1 << w); bit1++) {
            vector<vector<bool>> red(h, vector<bool>(w, false));   
            
            for (int i = 0; i < h; i++) {
               if (bit & 1 << i){
                   rep(j, 0, w){
                       red[i][j] = true;
                   }
                }
            }
            for (int i = 0; i < w; i++) {
                if (bit1 & 1 << i){
                    rep(j, 0, h){
                        red[j][i] = true;
                    }
                }
            }

            int count = 0;
            rep(i, 0, h){
                rep(j, 0, w){
                    if (grid[i][j] == '#' and !red[i][j]){
                        count++;
                    }
                }
            }

            if (count == k) res++;
        }
    }

    cout << res << endl;

}