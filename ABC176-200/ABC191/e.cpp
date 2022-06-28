#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define all(x) (x).begin(),(x).end()
const int INF = pow(10, 9) + 7;
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return true; } return false;}

struct Edge {
    int to;
    ll w;
    Edge(int to, ll w): to(to), w(w) {}
};

using Graph = vector<vector<Edge>>;

int main() {
    int N, M;
    cin >> N >> M;
    
    vector<vector<int>> dists(N, vector<int>(N, INF));
    rep(i, 0, M){
        int a, b, c; 
        cin >> a >> b >> c; a--; b--;
        dists[a][b] = min(dists[a][b], c);
    }
    
    Graph G(N);
    rep(i, 0, N){
        rep(j, 0, N){
            if (dists[i][j] != INF) G[i].push_back(Edge(j, dists[i][j]));
        }
    }

    rep(s, 0, N){
        vector<ll> dist(N, INF);
        ll res = INF;

        priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> que;
        que.push(make_pair(0, s)); // {距離, 頂点}

        while (!que.empty()) {
            int v = que.top().second;
            ll d = que.top().first;
            que.pop();

            if (v != s and d > dist[v]) continue;

            for (auto e: G[v]) {
                if (e.to == s) chmin(res, d + e.w);
                if (chmin(dist[e.to], d + e.w)) {
                    // cout << dist[e.to] << " " << e.to << endl;
                    que.push(make_pair(dist[e.to], e.to));
                }
            }        
        }
        cout << (res == INF ? -1: res) << endl;
    }

}