#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)

vector<vector<int>> graph;
vector<int> colors;
vector<int> c;
vector<int> res;
vector<int> seen;

bool dfs(int i){
    for (int e: graph[i]) {
        if (seen[e]) continue;

        seen[e] = 1;
        int color = c[e];
        if (!colors[color]) res.push_back(e+1);
        colors[color]++;
        dfs(e);
        colors[color]--;
        
    }

    return true;
}

int main() {
    int n;
    cin >> n;

    c.assign(n, 0);
    rep(i, 0, n) cin >> c[i];

    graph.assign(n, vector<int>());
    rep(i, 0, n-1){
        int a, b;
        cin >> a >> b; a--; b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    colors.assign(100100, 0);
    colors[c[0]]++;
    res.push_back(1);

    seen.assign(n, 0);
    seen[0] = 1;
    dfs(0);

    sort(res.begin(), res.end());
    for (auto i: res) {cout << i << endl;}
}