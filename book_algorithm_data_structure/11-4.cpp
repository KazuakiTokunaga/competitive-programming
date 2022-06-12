// Union-Find

#include <iostream>
#include <vector>
using namespace std;

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
    // 頂点数と辺数
    int n, m;
    cin >> n >> m;

    // Union-Findを要素数nで初期化
    UnionFind uf(n);

    // 各辺に対する処理
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        uf.unite(a, b);
    }

    // グループ数を集計
    int res = 0;
    for (int x = 0; x < n; ++x) {
        if (uf.root(x) == x) ++res;
    }
    cout << res << endl;
}