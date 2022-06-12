// ダイクストラ法（ヒープ）

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

    vector<ll> dist(n, INF);
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
            }
        }        
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