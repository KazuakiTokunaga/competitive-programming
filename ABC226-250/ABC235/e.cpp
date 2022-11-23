#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define all(x) (x).begin(),(x).end()

using Edge = pair<int, pii>;

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
    int N, M, Q;
    cin >> N >> M >> Q;

    UnionFind uf(N);

    vector<Edge> Edges;
    rep(i, 0, M){
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        Edges.push_back({c, {a, b}});
    }
    sort(all(Edges));
    reverse(all(Edges));

    vector<pair<Edge, int>> Queries;
    rep(i, 0, Q){
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        Queries.push_back({{w, {u, v}}, i});
    }
    sort(all(Queries));

    vector<int> res(Q, 0);
    rep(i, 0, Q){
        auto[edge, id] = Queries[i];
        auto[w, e] = edge;
        auto[u, v] = e;

        if (!Edges.empty()) {
            auto[c, e1] = Edges.back();
            while (c < w){
                uf.unite(e1.first, e1.second);
                Edges.pop_back();
                if (Edges.empty()) break;
                tie(c, e1) = Edges.back();
            }
        }        

        if (uf.issame(u, v)) res[id] = 0;
        else res[id] = 1;
    }

    rep(i, 0, Q) {
        if(res[i]) cout << "Yes" << endl; 
        else cout << "No" << endl;
    }
    
}