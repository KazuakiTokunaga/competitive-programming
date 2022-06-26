#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define all(x) (x).begin(),(x).end()

int H, W, K;
vector<vector<int>> grid;

int main() {
    cin >> H >> W >> K;
    grid.assign(H+1, vector<int>(W, 0));
    rep(i, 0, H){
        string s; 
        cin >> s;
        rep(j, 0, s.size()){
            grid[i][j] = int(s[j] - '0');
        }
    }

    int min_res = 10000;
    rep(i, 0, 1 << H){
        if (!(i & (1 << H-1))) continue;

        vector<vector<int>> comp;
        vector<int> h_comp(W, 0);
        int res = 0;
        bool check = true;

        rep(j, 0, H){
            rep(k, 0, W){
                h_comp[k] += grid[j][k];
                if (h_comp[k] > K) check = false;
            }
            if (i & (1 << j)){
                comp.push_back(h_comp);
                h_comp = vector<int>(W, 0);
                if (j != H-1) res++;
            }
        }
        
        // 横線の引き方の時点でNG.
        if (!check) continue;

        // rep(l, 0, comp.size()){
        //     for (auto m: comp[l]) {cout << m << ' ';} cout << endl;
        // }
        
        rep(j, 0, W-1){
            bool check = true;
            rep(k, 0, comp.size()){
                if (comp[k][j+1] + comp[k][j] > K) check = false;
            }
            if (check){
                rep(k, 0, comp.size()){
                    comp[k][j+1] += comp[k][j];
                }
            } else {
                res++;
            }
        }

        min_res = min(res, min_res);
    }

    cout << min_res << endl;
}