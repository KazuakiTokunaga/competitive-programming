// 木上の動的計画法(各頂点の深さと部分木のサイズを求める)

#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;

vector<int> depth;
vector<int> subtree_size;
void dfs(const Graph &G, int v, int p = -1, int d = 0) {
    depth[v] = d;
    for (auto c: G[v]) {
        if (c == p) continue;
        dfs(G, c, v, d+1);
    }

    subtree_size[v] = 1;
    for (auto c: G[v]) {
        if (c == p) continue;

        subtree_size[v] += subtree_size[c];
    }
}

int main() {
    int n,m;
    cin >> n >> m;
    
    Graph G (n);
    for (int i = 0; i < m; i++) {
        int a,b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    int root = 0;
    depth.assign(n, 0);
    subtree_size.assign(n, 0);
    dfs(G, root);

    for (int v = 0; v < n; v++) {
        cout << v << ": depth = " << depth[v]
        << ", subtree_size = " << subtree_size[v] << endl;
    }
}