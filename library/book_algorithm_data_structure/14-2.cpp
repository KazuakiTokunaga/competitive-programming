// ベルマン・フォード法

#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll INF = 1LL << 60;

struct Edge {
    int to;
    ll w;
    Edge(int to, ll w): to(to), w(w) {}
};

using Graph = vector<vector<Edge>>;

template<class T> bool chmin(T& a, T b){
    if (a>b) {
        a = b;
        return true;
    } else {
        return false;
    }
}

int main() {
    int n, m, s;
    cin >> n >> m >> s;
    
    Graph G(n);
    for (int i = 0; i < m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        G[a].push_back(Edge(b,w));
    }

    bool exist_negative_cycle = false;
    vector<ll> dist(n, INF);
    dist[s] = 0;
    for (int iter = 0; iter < n; iter++) {
        bool update = false;
        for (int v = 0; v < n; v++) {
            if (dist[v] == INF) continue;

            for (auto e: G[v]) {
                if (chmin(dist[e.to], dist[v] + e.w)) {
                    update = true;
                }
            }
        }

        if (!update) break;

        if (iter ==  n-1 && update) exist_negative_cycle = true;
    }

    if (exist_negative_cycle) cout << "Negative Cycle" << endl;
    else {
        for (int v = 0; v < n; v++) {
            if (dist[v] < INF) cout << dist[v] << endl;
            else cout << "INF" << endl;
        }
    }

}

/*
入力例
6 12 0
0 1 3
0 3 100
1 3 57
3 1 -5
1 2 50
1 4 -4
2 3 -10
4 3 25
2 4 -5
4 2 57
2 5 100
4 5 8
*/