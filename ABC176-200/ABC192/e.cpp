#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
const ll INF = 1LL << 60;

template<class T> bool chmin(T& a, T b){
    if (a>b) {
        a = b;
        return true;
    } else {
        return false;
    }
}

struct Edge {
    int to;
    int t;
    int k;
    Edge(int to, int t, int k): to(to), t(t), k(k) {}
};

using Graph = vector<vector<Edge>>;

int main() {
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    
    Graph G(n+1);
    for (int i = 0; i < m; i++) {
        int a, b, t, k;
        cin >> a >> b >> t >> k;
        G[a].push_back(Edge(b, t, k));
        G[b].push_back(Edge(a, t, k));
    }

    vector<ll> dist(n+1, INF);
    dist[x] = 0;

    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> que;
    que.push(make_pair(dist[x], x));

    while (!que.empty()) {
        int v = que.top().second;
        ll d = que.top().first;
        que.pop();

        if (d > dist[v]) continue;

        for (auto e: G[v]) {
            ll depart = dist[v];
            if (dist[v] % e.k != 0) {
                ll wait = e.k - dist[v] % e.k;
                depart += wait;
            }
            ll eta = depart + e.t;

            if (chmin(dist[e.to], eta)) {
                que.push(make_pair(dist[e.to], e.to));
            }
        }        
    }

    // for (auto i: dist) {cout << i << ' ';} cout << endl;
    if (dist[y] == INF) cout << -1 << endl;
    else cout << dist[y] << endl;

}