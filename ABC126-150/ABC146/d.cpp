#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)

struct Edge {
    int to;
    int id;
    Edge(int to, int i): to(to), id(i) {}
};
using Graph = vector<vector<Edge>>;

int main() {
    int n;
    cin >> n;
    
    Graph G(n+1);
    vector<int> colors(n-1, 0);
    for (int i = 0; i < n-1; i++) {
        int a,b;
        cin >> a >> b;
        G[a].push_back(Edge(b, i));
        G[b].push_back(Edge(a, i));
    }

    int max_length = 0;
    rep(i, 0, n){
        max_length = max(max_length, (int)G[i].size());
    }

    rep(i, 1, n+1){
        vector<int> used(max_length+1, -1);
        for (auto e: G[i]) {
            used[colors[e.id]] = 1;
        }
        for (auto e: G[i]){
            if (colors[e.id] != 0) continue;
            rep(c, 1, max_length+1){
                if (used[c] != 1) {
                    colors[e.id] = c;
                    used[c] = 1;
                    break;
                };
            }
        }
    }

    cout << max_length << endl;
    for (int i: colors) {
        cout << i << endl;
    }
}

