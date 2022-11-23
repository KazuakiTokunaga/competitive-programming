#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define all(x) (x).begin(),(x).end()

struct UnionFind {
    vector<int> par, siz, lit;

    UnionFind(int n) : par(n, -1) , siz(n, 1), lit(n, 0) { }

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
        if (islight(y)) lit[x] = 1;
        par[y] = x;
        siz[x] += siz[y];
        return true;
    }

    // xを含むグループのサイズ
    int size(int x) {
        return siz[root(x)];
    }

    bool islight(int x){
        return lit[root(x)];
    }

    void setlight(int x){
        lit[root(x)] = 1;
    }
};

int main() {
    int N, M, E;
    cin >> N >> M >> E;
    
    vector<pii> lines;
    rep(i, 0, E){
        int u, v;
        cin >> u >> v; u--; v--;
        lines.push_back({u, v});
    }

    int Q;
    cin >> Q;
    vector<int> Events;
    vector<int> Effective(E, 1);
    rep(i, 0, Q){
        int x; 
        cin >> x; x--;
        Events.push_back(x);
        Effective[x] = 0;
    }

    // 最後の状態の塊の状況をunion findで表現
    vector<int> lighton(N, 0);
    UnionFind uf(N);
    rep(i, 0, E){
        if (!Effective[i]) continue;

        auto [u, v] = lines[i];
        if (u >= N and v < N) uf.setlight(v);
        if (v >= N and u < N) uf.setlight(u);
        if (u < N and v < N) uf.unite(u, v);
    }

    // 最後の状態で電気がついている都市をカウント
    int cur = 0;
    rep(i, 0, N) if (uf.islight(i)) cur++;
    vector<int> res = {cur};

    rrep(i, Q-1, 0){
        // 復旧させる電線
        int e = Events[i];
        auto [u, v] = lines[e];

        // 都市以外が含まれている場合を先に処理
        bool elec = false;
        if (max(u, v) >= N) elec = true;
        if (u >= N and v < N) if (!uf.islight(v)) {cur += uf.size(v); uf.setlight(v);}
        if (v >= N and u < N) if (!uf.islight(u)) {cur += uf.size(u); uf.setlight(u);}
        if (elec) {res.push_back(cur); continue;}

        // 両方ともに都市の時
        if (!uf.islight(u) and uf.islight(v)) cur += uf.size(u);
        if (!uf.islight(v) and uf.islight(u)) cur += uf.size(v);
        if (!uf.issame(u, v)) uf.unite(u, v);
        res.push_back(cur);
    }

    reverse(all(res));
    rep(i, 1, res.size()){
        cout << res[i] << endl;
    }
}