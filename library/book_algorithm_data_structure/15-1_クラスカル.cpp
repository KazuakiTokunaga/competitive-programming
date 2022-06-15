// 最小全域木（クラスカル法）

#include <bits/stdc++.h>
#define ll long long
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

// 辺：第一引数が重さ、第二引数が結ぶ頂点を表す
using Edge = pair<int, pair<int, int>>;

int main() {
    // 頂点数と辺数
    int n, m;
    cin >> n >> m;

    vector<Edge> edges(m);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges[i] = Edge(w, make_pair(u,v));
    }

    sort(edges.begin(), edges.end());
    
    ll res = 0;
    UnionFind uf(n);
    for (int i = 0; i < m; i++) {
        int w = edges[i].first;
        int u = edges[i].second.first;
        int v = edges[i].second.second;

        if (uf.issame(u, v)) continue;

        res += w;
        uf.unite(u,v);
    }

    cout << res << endl;
}

/*
入力例（図15.2）
8 12
4 2 9
4 1 4
4 6 2
6 1 3
1 3 8
6 7 7
7 3 6
2 7 5
2 5 10
5 0 6
0 3 5
7 0 3
*/