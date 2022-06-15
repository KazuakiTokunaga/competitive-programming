// https://algo-logic.info/lca/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)

struct Edge {
    int to;
    Edge(int to): to(to) {}
};
using Graph = vector<vector<Edge>>;

/* LCA(G, root): 木 G に対する根を root として Lowest Common Ancestor を求める構造体
    query(u,v): u と v の LCA を求める。計算量 O(logn)
    前処理: O(nlogn)時間, O(nlogn)空間
*/
struct LCA {
    vector<vector<int>> parent;  // parent[k][u]:= u の 2^k 先の親
    vector<int> dist;            // root からの距離
    LCA(const Graph &G, int root = 0) { init(G, root); }

    // 初期化
    void init(const Graph &G, int root = 0) {
        int V = G.size();
        int K = 1;
        while ((1 << K) < V) K++;
        parent.assign(K, vector<int>(V, -1));
        dist.assign(V, -1);
        dfs(G, root, -1, 0);
        for (int k = 0; k + 1 < K; k++) {
            for (int v = 0; v < V; v++) {
                if (parent[k][v] < 0) {
                    parent[k + 1][v] = -1;
                } else {
                    parent[k + 1][v] = parent[k][parent[k][v]];
                }
            }
        }
    }

    // 根からの距離と1つ先の頂点を求める
    void dfs(const Graph &G, int v, int p, int d) {
        parent[0][v] = p;
        dist[v] = d;
        for (auto e : G[v]) {
            if (e.to != p) dfs(G, e.to, v, d + 1);
        }
    }

    int query(int u, int v) {
        if (dist[u] < dist[v]) swap(u, v);  // u の方が深いとする
        int K = parent.size();
        // LCA までの距離を同じにする
        for (int k = 0; k < K; k++) {
            if ((dist[u] - dist[v]) >> k & 1) {
                u = parent[k][u];
            }
        }
        // 二分探索で LCA を求める
        if (u == v) return u;
        for (int k = K - 1; k >= 0; k--) {
            if (parent[k][u] != parent[k][v]) {
                u = parent[k][u];
                v = parent[k][v];
            }
        }
        return parent[0][u];
    }

    // uとvの距離
    int get_dist(int u, int v) { 
        return dist[u] + dist[v] - 2 * dist[query(u, v)]; 
    }

    // uとvを結ぶパスに頂点aがあるかどうか
    bool is_on_path(int u, int v, int a) { 
        return get_dist(u, a) + get_dist(a, v) == get_dist(u, v); 
    }
};

int main(){
    Graph g(10, vector<Edge>());
    vector<pii> edges = {{0,1},{1,2},{1,3},{2,4},{2,5},{0,6},{6,7},{7,8},{8,9}};
    for (pii edge: edges) {
        g[edge.first].push_back(Edge(edge.second));
    }

    LCA lca(g, 0);
    cout << lca.query(4, 3) << endl;
    cout << lca.get_dist(3, 8) << endl;
    cout << (lca.is_on_path(5, 7, 1) ? "True":"False") << endl;
}



