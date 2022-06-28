#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define all(x) (x).begin(),(x).end()

int main() {
    int H, W, N, M;
    cin >> H >> W >> N >> M;

    vector<vector<int>> grid(H, vector<int>(W, 0));
    vector<vector<int>> C_light(W, vector<int>());
    vector<vector<int>> C_block(W, vector<int>());
    vector<vector<int>> R_light(H, vector<int>());
    vector<vector<int>> R_block(H, vector<int>());

    rep(i, 0, N){
        int a, b;
        cin >> a >> b; a--; b--;
        R_light[a].push_back(b);
        C_light[b].push_back(a);
    }

    rep(i, 0, M){
        int c, d;
        cin >> c >> d; c--; d--;
        R_block[c].push_back(d);
        C_block[d].push_back(c);
    }

    rep(i, 0, H){
        R_light[i].push_back(-2);
        R_light[i].push_back(W+2);
        sort(all(R_light[i]));

        R_block[i].push_back(-1);
        R_block[i].push_back(W+1);
        sort(all(R_block[i]));
    }
    rep(i, 0, W){
        C_light[i].push_back(-2);
        C_light[i].push_back(H+2);
        sort(all(C_light[i]));

        C_block[i].push_back(-1);
        C_block[i].push_back(H+1);
        sort(all(C_block[i]));
    }

    rep(i, 0, H){
        int light_idx_f = 1, block_idx_f = 1, light_idx_b = 0, block_idx_b = 0;
        int light_f = R_light[i][light_idx_f], block_f = R_block[i][block_idx_f];
        int light_b = R_light[i][light_idx_b], block_b = R_block[i][block_idx_b];
        rep(j, 0, W){
            if (j > light_f){
                light_idx_b = light_idx_f;
                light_b = R_light[i][light_idx_b];

                light_idx_f++;
                light_f = R_light[i][light_idx_f];
            }
            if (j > block_f){
                block_idx_b = block_idx_f;
                block_b = R_block[i][block_idx_b];

                block_idx_f++;
                block_f = R_block[i][block_idx_f];
            }
            if (j == block_b or j == block_f) continue;
            if (j <= light_f and light_f < block_f) grid[i][j] = 1;
            if (block_b < light_b and light_b <= j) grid[i][j] = 1;
        }
    }

    rep(i, 0, W){
        int light_idx_f = 1, block_idx_f = 1, light_idx_b = 0, block_idx_b = 0;
        int light_f = C_light[i][light_idx_f], block_f = C_block[i][block_idx_f];
        int light_b = C_light[i][light_idx_b], block_b = C_block[i][block_idx_b];
        rep(j, 0, H){
            if (j > light_f){
                light_idx_b = light_idx_f;
                light_b = C_light[i][light_idx_b];

                light_idx_f++;
                light_f = C_light[i][light_idx_f];
            }
            if (j > block_f){
                block_idx_b = block_idx_f;
                block_b = C_block[i][block_idx_b];

                block_idx_f++;
                block_f = C_block[i][block_idx_f];
            }
            if (j == block_b or j == block_f) continue;
            if (j <= light_f and light_f < block_f) grid[j][i] = 1;
            if (block_b < light_b and light_b <= j) grid[j][i] = 1;
        }
    }

    int res = 0;
    rep(i, 0, H){
        rep(j, 0, W){
            if (grid[i][j]) res++;
        }
    }

    // rep(i, 0, H){
    //     for (auto j: grid[i]) {cout << j << ' ';} cout << endl;
        
    // }

    cout << res << endl;
}