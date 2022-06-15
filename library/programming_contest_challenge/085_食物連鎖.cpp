#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define all(x) (x).begin(),(x).end()

struct UnionFind {
    vector<int> par, siz;

    UnionFind(int n) : par(n, -1) , siz(n, 1) { }

    // 根を求める
    int root(int x) {
        if (par[x] == -1) return x;
        else return par[x] = root(par[x]);
    }

    // xとyが同じグループに属するかどうか
    bool issame(int x, int y) {
        return root(x) == root(y);
    }

    // xを含むグループとyを含むグループを併合
    bool unite(int x, int y) {
        x = root(x), y = root(y);
        if (x == y) return false; 
        if (siz[x] < siz[y]) swap(x, y);
        par[y] = x;
        siz[x] += siz[y];
        return true;
    }

    // xを含むグループのサイズ
    int size(int x) {
        return siz[root(x)];
    }
};

int main() {
    int n, k;
    cin >> n >> k;

    UnionFind uf(3*n);

    int res = 0;
    rep(i, 0, k){
        int t, x, y;
        cin >> t >> x >> y; x--; y--;

        if (x < 0 or x >= n or y < 0 or y >= n) {
            res++; continue;
        }

        if (t==1){
            if (uf.issame(x, y+n) or uf.issame(x, y+2*n)){
                res++;
            } else {
                uf.unite(x, y);
                uf.unite(x+n, y+n);
                uf.unite(x+2*n, y+2*n);
            }
        } else {
            if (uf.issame(x, y) or uf.issame(x , y+2*n)){
                res++;
            } else{
                uf.unite(x, y+n);
                uf.unite(x+n, y+ 2*n);
                uf.unite(x+2*n, y);
            }
        }
    }

    cout << res << endl;
}

/*
100 7
1 101 1
2 1 2
2 2 3
2 3 3
1 1 3
2 3 1
1 5 5
*/