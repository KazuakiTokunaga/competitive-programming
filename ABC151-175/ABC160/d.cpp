#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
const int INF = pow(10, 9) + 7;
using Graph = vector<vector<int>>;

bool bfs(Graph &G, vector<int> &d, queue<int> &q, int i){
    for (int e: G[i]) {
        if (d[e] != INF) continue;
        else {
            // cout << "smooth" << endl;
            d[e] = d[i] + 1;
            q.push(e);
        }
    }

    if (!q.empty()){
        int v = q.front(); q.pop();
        bfs(G, d, q, v);
    }

    return true;
}

int main() {
    int n, x, y;
    cin >> n >> x >> y;
    
    Graph G(n+1);
    rep(i, 1, n){
        G[i].push_back(i+1);
        G[i+1].push_back(i);
    }
    G[x].push_back(y);
    G[y].push_back(x);

    vector<vector<int>> dmatrix(n+1);
    rep(i, 1, n+1){
        vector<int> d(n+1, INF);
        queue<int> q;
        d[i] = 0;
        bfs(G, d, q, i);

        rep(j, 1, n+1){
            dmatrix[i].push_back(d[j]);
        }
    }

    vector<int> res(n, 0);
    rep(i, 1, n+1){
        rep(j, i, n+1){
            res[dmatrix[i][j]]++;
        }
    }

    rep(i, 1, n){
        cout << res[i] << endl;
    }
    
}