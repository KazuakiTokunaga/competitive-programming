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
    int n, m;
    cin >> n >> m;

    // Union-Findを要素数nで初期化
    UnionFind uf(n+1);

    rep(i, 0, m){
        int x, y, z;
        cin >> x >> y >> z;

        uf.unite(x, y);
    }

    vector<int> cnt(n+1, 0);
    int res = 0;
    rep(i, 1, n+1){
        int c = uf.root(i);
        if (cnt[c]) continue;
        else {
            cnt[c]++;
            res++;
        }
    }

    cout << res << endl;
}