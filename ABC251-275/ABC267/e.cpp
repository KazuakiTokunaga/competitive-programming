#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<ll, ll>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define all(x) (x).begin(),(x).end()

int main() {
    int N, M;
    cin >> N >> M;

    vector<ll> A(N);
    rep(i, 0, N) cin >> A[i];
    
    vector<vector<int>> graph(N);
    rep(i, 0, M){
        int u, v;
        cin >> u >> v;
        u--; v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    // 最初の各辺を消去したときのスコア
    vector<ll> p(N, 0);
    rep(i, 0, N){
        for (int v: graph[i]) {
            p[v] += A[i];
        }
    }

    ll res = -1;
    priority_queue<pii, vector<pii>, greater<pii>> q;
    vector<int> used(N, 0);
    rep(i, 0, N) q.push({p[i], i});
    while (!q.empty()){
        auto[s, i] = q.top(); q.pop();
        if (used[i]) continue; // ゴミ
        if (s != p[i]) continue; // ゴミ

        used[i] = 1;
        res = max(res, s);
        for (int v: graph[i]) {
            p[v] -= A[i];
            q.push({p[v], v});
        }
    }

    cout << res << endl;
}