#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define all(x) (x).begin(),(x).end()

int N;
vector<int> res;
vector<int> used(100100, 0);
vector<int> passed(100100, 0);
vector<int> colors(100100, 0);
vector<vector<int>> graph;

void dfs(int c){
    int color = colors[c];
    if (!used[color]) res.push_back(c);
    used[color]++;
    passed[c] = 1;

    for (int nxt: graph[c]) {
        if (passed[nxt]) continue;

        int nxt_color = colors[nxt];    
        dfs(nxt);
        used[nxt_color]--;
    }
}

int main() {
    cin >> N;
    rep(i, 0, N) cin >> colors[i];

    graph.assign(N, vector<int>());
    rep(i, 0, N-1){
        int a, b;
        cin >> a >> b; a--; b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    dfs(0);
    sort(all(res));
    for (int i: res) {
        cout << i+1 << endl;
    }
    




}