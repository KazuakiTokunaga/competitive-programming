#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define all(x) (x).begin(),(x).end()
const ll INF = 2LL << 60;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false;}

struct Edge {
    int from;
    int to;
    ll w;
    Edge(int from, int to, ll w): from(from), to(to), w(w) {}
};

// 最悪計算量がダメな解法に思われるが、通る
// 
int main() {    
    int N, M;
    cin >> N >> M;
    
    vector<int> H(N);
    rep(i, 0, N) cin >> H[i];

    vector<vector<Edge>> graph(N);
    rep(i, 0, M){
        int u, v;
        cin >> u >> v; u--; v--;

        ll d = (H[u] - H[v] > 0 ? H[u] - H[v]: 2*(H[u] - H[v]));
        graph[u].push_back(Edge(u, v, d));

        ll d1 = (H[v] - H[u] > 0 ? H[v] - H[u]: 2*(H[v] - H[u]));
        graph[v].push_back(Edge(v, u, d1));
    }

    auto c = [](Edge l, Edge r) { return l.w <= r.w; };
    priority_queue<Edge, vector<Edge>, decltype(c)> q(c);

    vector<ll> point(N, -INF);
    point[0] = 0;
    for (auto nxt: graph[0]) {
        q.push(nxt);
    }

    ll res = 0;
    while (!q.empty()){
        Edge cur = q.top(); q.pop();
        if (chmax(point[cur.to], point[cur.from] + cur.w)){
            res = max(res, point[cur.to]);

            for (Edge nxt: graph[cur.to]) {
                q.push(nxt);
            }
        }
    }

    cout << res << endl;
}

/*
6 6
10 9 10 11 12 1
1 2
2 3
3 4
4 5
1 5
5 6

のような入力のとき、chmax()の更新が多く発生して計算量が増える
*/