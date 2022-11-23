// 反転。2次元座標で1行目の決め方だけ全探索する
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define all(x) (x).begin(),(x).end()

int M, N;
vector<vector<int>> tile;
vector<vector<int>> opt;
vector<vector<int>> flip;
vector<pii> dxdy = {{-1, 0}, {0, -1}, {0, 0}, {0, 1}, {1, 0}};

int get(int x, int y){
    int c = tile[x][y];

    // 周囲のマスが反転しているかどうかを確認して反映する
    for (pii p: dxdy) {
        int a, b;
        tie(a,b) = p;
        int x2 = x + a, y2 = y + b;
        if (0 <= x2 && x2 < M && 0 <= y2 && y2 < N){
            c += flip[x2][y2];
        }
    }

    return c % 2;
}

int calc() {
    // 2行目からのひっくり返し方を求める
    rep(i, 1, M){
        rep(j, 0, N){
            if (get(i-1, j) != 0){
                flip[i][j] = 1;
            }
        }
    }

    rep(i, 0, N){
        if (get(M-1, i) != 0) return -1;
    }

    int res = 0;
    rep(i, 0, M){
        rep(j, 0, N){
            res += flip[i][j];
        }
    }
    
    return res;
}

int main() {
    cin >> M >> N;

    tile.assign(M, vector<int>(N, 0));
    opt.assign(M, vector<int>(N, 0));
    rep(i, 0, M){
        rep(j, 0, N){
            cin >> tile[i][j];
        }
    }

    int res = -1;

    // 1行目のひっくり返し方をbit全探索
    for (int i = 0; i < 1 << N; i++) {
        flip.assign(M, vector<int>(N, 0));
        
        // bit演算で1行目のひっくり返し方を確認
        rep(j, 0, N){
            if (i & 1 << j) flip[0][N-j-1] = 1;
            else flip[0][N-j-1] = 0;
        }

        int num = calc();
        if (num >= 0 && (res < 0 || res > num)){
            res = num;
            opt = flip;
        }
    }

    if (res < 0) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        rep(i, 0, M){
            rep(j, 0, N){
                cout << opt[i][j] << " ";
            }
            cout << endl;
        }
    }
}

/*
4 4
1 0 0 1
0 1 1 0
0 1 1 0
1 0 0 1
*/