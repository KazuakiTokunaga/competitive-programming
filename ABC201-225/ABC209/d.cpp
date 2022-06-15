#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)

vector<int> color;
vector<vector<int>> graph;

bool dfs(int i, int c){
    if (color[i] != -1) return true;
    color[i] = c;

    for (int e: graph[i]) {
        dfs(e, 1-c);
    }

    return true;
}

int main() {
    int n, q;
    cin >> n >> q;

    color.assign(n+1, -1);
    graph.assign(n+1, vector<int>());
    rep(i, 0, n-1){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    dfs(1, 0);

    rep(i, 0, q){
        int c, d;
        cin >> c >> d;

        if (color[c] == color[d]) cout << "Town" << endl;
        else cout << "Road" << endl;
    }
}