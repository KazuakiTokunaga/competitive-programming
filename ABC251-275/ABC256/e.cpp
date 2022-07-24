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
    int N;
    cin >> N;
    
    vector<int> X(N);
    rep(i, 0, N) {cin >> X[i]; X[i]--;}
    
    vector<int> C(N);
    rep(i, 0, N) cin >> C[i];

    UnionFind uf(N);

    ll res = 0;
    vector<int> used(N, 0);
    rep(i, 0, N){
        if (!uf.issame(i, X[i])){
            uf.unite(i, X[i]);
            continue;
        }

        // こちらに来た場合、既にサイクルが完成しているのでそれをカウントする
        // このサイクルを重複カウントするような場合は起こり得ない
        int cur = C[i], v = i;
        while (true) {
            v = X[v];
            cur = min(cur, C[v]);
            if (v == i) break;
        }
        res += cur;
    }
    cout << res << endl;
}