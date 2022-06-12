#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)

struct Edge {
    int to;
    ll w;
    Edge(int to, ll w): to(to), w(w) {}
};

using Graph = vector<vector<Edge>>;
vector<int> colors;

bool dfs(const Graph &G, int v, int color = 0){
    if (colors[v] != -1) return true;
    colors[v] = color;
    for (auto e: G[v]) {
        if (color != -1){
            if (e.w % 2 == 0) {
                if (dfs(G, e.to, color)) continue;
                else return false;
            } else {
                if (dfs(G, e.to, 1-color)) continue;
                else return false;
            }
        } else {
            if (e.w % 2 == 0){
                if (colors[e.to] == color) continue;
                else return false;
            } else {
                if (colors[e.to] != color) continue;
                else return false;
            }
        }
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    
    Graph G(n+1);
    for (int i = 0; i < n-1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        G[u].push_back(Edge(v,w));
        G[v].push_back(Edge(u,w));
    }
    
    colors.assign(n+1, -1);
    if (!dfs(G, 1, 0)) cout << "something went wrong!" << endl;
    else {
        rep(i, 1, n+1){
            cout << colors[i] << endl;
        }
    }
}