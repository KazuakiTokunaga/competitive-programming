// ダイクストラ法
// 負辺がない場合のみ. 計算量はO(V^2). 
// 辺が多いグラフではヒープを使うよりも有利

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

    vector<bool> used(n, false);
    vector<ll> dist(n, INF);
    dist[s] = 0;

    for (int iter = 0; iter < n; iter++) {
        ll min_dist = INF;
        int min_v = -1;

        for (int v = 0; v < n; v++) {
            if (!used[v] && dist[v] <= min_dist){
                min_dist = dist[v];
                min_v = v;
            }
        }

        if (min_v == -1) break;

        for (auto e: G[min_v]) {
            chmin(dist[e.to], dist[min_v] + e.w);
        }
        used[min_v] = true;
    }

    for (int v = 0; v < n; v++) {
        if (dist[v] < INF) cout << dist[v] << endl;
        else cout << "INF" << endl;
    }
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