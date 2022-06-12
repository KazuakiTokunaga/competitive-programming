// 木上の動的計画法

#include <bits/stdc++.h>
#define ll long long
using namespace std;
using Graph = vector<vector<int>>;

vector<ll> ans;
void dfs(const Graph &G, int v, int p = -1) {
    for (auto c: G[v]) {
        if (c == p) continue;
        ans[c] += ans[v];
        dfs(G, c, v);
    }
}

int main() {
    int n,q;
    cin >> n >> q;
    
    Graph G(n+1);
    for (int i = 0; i < n-1; i++) {
        int a,b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    ans.assign(n+1,0);
    for (int i = 0; i < q; i++) {
        int p,x;
        cin >> p >> x;
        ans[p] += x;
    }

    dfs(G, 1);

    for (int i = 1; i < n+1; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
}