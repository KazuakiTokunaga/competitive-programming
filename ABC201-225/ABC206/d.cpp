#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)

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
    int n;
    cin >> n;

    deque<int> a;
    rep(i, 0, n) {
        int t;
        cin >> t;
        a.push_back(t);
    }
    
    UnionFind uf(200010);
    int cnt = 0;

    while (!a.empty()){
        int s = a.back(); a.pop_back();
        if (a.empty()) break;
        int t = a.front(); a.pop_front();

        // cout << s << " " << t << " " << (uf.issame(s,t) ? "true":"no") << endl;
        if (s == t or uf.issame(s,t)) continue;
        else {
            cnt++;
            uf.unite(s, t);
        }
    }

    cout << cnt << endl;
}