// グラフにおいて2番目の最短路を求める

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define all(x) (x).begin(),(x).end()
const int INF = pow(10, 9) + 7;

struct Edge {
    int to;
    ll c;
    Edge(int to, ll c): to(to), c(c) {}
};

int main() {
    int n, r;
    cin >> n >> r;

    vector<vector<Edge>> graph(n);
    rep(i, 0, r){
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back(Edge(b, c));
        graph[b].push_back(Edge(a, c));
    }

    vector<int> dist(n, INF);
    vector<int> dist2(n, INF);
    priority_queue<pii, vector<pii>, greater<pii>> que;
    dist[0] = 0; dist2[0] = 0;
    que.push(make_pair(0, 0));

    while (!que.empty()){
        int v, d;
        tie(d, v) = que.top(); que.pop();

        if (dist2[v] < d) continue;
        for (auto e: graph[v]) {
            int d2 = d + e.c;
            if (dist[e.to] > d2){
                swap(dist[e.to], d2);
                que.push(make_pair(dist[e.to], e.to));
            }
            if (dist2[e.to] > d2 and dist[e.to] < d2){
                dist2[e.to] = d2;
                que.push(make_pair(dist2[e.to], e.to));
            }
        }
    }

    for (auto i: dist2) {cout << i << ' ';} cout << endl;
}

/*
4 4
0 1 100
1 3 200
2 3 100
1 2 250
*/