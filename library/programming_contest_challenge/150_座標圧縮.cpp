#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define all(x) (x).begin(),(x).end()

int W, H, N;
vector<int> X1, X2, Y1, Y2;

// 2次元の座標圧縮はこちらを採用した
// https://algo-logic.info/coordinate-compress/#toc_id_2

/* compress
    (X1,Y1),(X2,Y2)という二点で表されるもの（長方形や直線など）について、行か列の片方（X1とX2 or Y1とY2）を座標圧縮する
    座標は1始まりで、最大幅wを超えるものは含めない
    返り値: ソートされ重複要素を除いた値
    計算量: O(n log n)
*/
template <typename T>
vector<T> compress(vector<T> &C1, vector<T> &C2, int w) {
    vector<T> vals;
    int N = (int)C1.size();
    for (int i = 0; i < N; i++) {
        for (T d = -1; d <= 1; d++) {  // その位置と、両隣を確保
            T tc1 = C1[i] + d;
            T tc2 = C2[i] + d;
            if (tc1 >= 1 and tc1 <= w) vals.push_back(tc1);
            if (tc2 >= 1 and tc2 <= w) vals.push_back(tc2);
        }
    }
    // ソート
    sort(vals.begin(), vals.end());
    // 隣り合う重複を削除(unique), 末端のゴミを削除(erase)
    vals.erase(unique(vals.begin(), vals.end()), vals.end());
    for (int i = 0; i < N; i++) {
        C1[i] = lower_bound(vals.begin(), vals.end(), C1[i]) - vals.begin();
        C2[i] = lower_bound(vals.begin(), vals.end(), C2[i]) - vals.begin();
    }
    return vals;
}

int main() {
    cin >> W >> H >> N;

    rep(i, 0, N){
        int x; cin >> x;
        X1.push_back(x);
    }
    rep(i, 0, N){
        int x; cin >> x;
        X2.push_back(x);
    }
    rep(i, 0, N){
        int y; cin >> y;
        Y1.push_back(y);
    }
    rep(i, 0, N){
        int y; cin >> y;
        Y2.push_back(y);
    }

    vector<int> xvals = compress(X1, X2, W);
    W = xvals.size();
    vector<int> yvals = compress(Y1, Y2, H);
    H = yvals.size();
    

    // 以下はほぼ蟻本そのまま
    vector<vector<bool>> fld(H+1, vector<bool>(W+1, false));
    rep(i, 0, N){
        rep(y, Y1[i], Y2[i]+1){
            rep(x, X1[i], X2[i]+1){
                fld[y][x] = true;
            }
        }
    }
    
    int res = 0;
    vector<pii> dxdy = {{-1,0},{1,0},{0,-1},{0,1}};
    rep(y, 0, H){
        rep(x, 0, W){
            if (fld[y][x]) continue;
            res++;

            queue<pii> que;
            que.push(make_pair(y, x));
            while (!que.empty()){
                int sy = que.front().first, sx = que.front().second;
                que.pop();

                rep(k, 0, 4){
                    int dx, dy;
                    tie(dy,dx) = dxdy[k];
                    int tx = sx + dx, ty = sy + dy;
                    if (tx < 0 or tx >= W or ty < 0 or ty >= H) continue;
                    if (fld[ty][tx]) continue;
                    que.push(make_pair(ty,tx));
                    fld[ty][tx] = true;
                }
            }
        }
    }

    cout << res << endl;
}

/*
10 10 5
1 1 4 9 10
6 10 4 9 10
4 8 1 1 6
4 8 10 5 10
*/