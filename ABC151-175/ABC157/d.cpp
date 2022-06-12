#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
using Graph = vector<vector<int>>;

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
    int n, m, k;
    cin >> n >> m >> k;

    UnionFind uf(n+1);
    vector<int> friends(n+1, 0);
    vector<int> res(n+1, 0);
    for (int i = 0; i < m; i++) {
        int a,b;
        cin >> a >> b;
        uf.unite(a,b);
        friends[a]++;
        friends[b]++;
    }

    rep(i, 1, n+1){
        res[i] = uf.size(i) - friends[i] - 1;
    }

    rep(i, 0, k){
        int c, d;
        cin >> c >> d;
        if (uf.issame(c, d)){
            res[c]--;
            res[d]--;
        }
    }

    rep(i, 1, n+1){
        cout << res[i] << " ";
    }
    cout << endl;
}