// ダイクストラ法（ヒープ）
// 負辺がない場合のみ. 計算量はO(ElogV). 
// 辺が少ないグラフではこちらのほうが有利.

#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll INF = 1LL << 60;
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return true; } return false;}

struct Edge {
    int to;
    ll w;
    Edge(int to, ll w): to(to), w(w) {}
};

using Graph = vector<vector<Edge>>;

int main() {
    int n, m, s;
    cin >> n >> m >> s;
    
    Graph G(n);
    for (int i = 0; i < m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        G[a].push_back(Edge(b,w));
    }

    vector<ll> dist(n, INF);
    vector<int> prev(n, -1); // 経路復元
    dist[s] = 0;

    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> que;
    que.push(make_pair(dist[s], s));

    while (!que.empty()) {
        int v = que.top().second;
        ll d = que.top().first;
        que.pop();

        if (d > dist[v]) continue;

        for (auto e: G[v]) {
            if (chmin(dist[e.to], dist[v] + e.w)) {
                que.push(make_pair(dist[e.to], e.to));
                prev[e.to] = v; // e.toの前の頂点を保存
            }
        }        
    }

    for (int v = 0; v < n; v++) {
        if (dist[v] < INF) cout << dist[v] << endl;
        else cout << "INF" << endl;
    }


    // 経路復元：頂点s -> 5までの最短路の経路（蟻本p.98)
    vector<int> path;
    int cur = 5; path.push_back(cur);
    while (cur != s){
        cur = prev[cur];
        path.push_back(cur);
    }
    reverse(path.begin(), path.end());
    for (auto i: path) {cout << i << ' ';} cout << endl;
    
}

/*
入力例
6 9 0
0 1 3
0 2 5
1 2 4
2 3 9
2 4 4
4 3 7
1 3 12
4 5 8
3 5 2
*/