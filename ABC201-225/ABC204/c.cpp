#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)

vector<vector<int>> graph;
int cnt = 0;

bool dfs(int i, vector<int> &used){
    if (used[i]) return true;
    used[i] = 1;
    cnt++;

    for (int e: graph[i]) {
        dfs(e, used);
    }
    return true;
}

int main() {
    int n, m;
    cin >> n >> m;

    graph.assign(n+1, vector<int>());
    rep(i, 0, m){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
    }

    int res = 0;
    rep(i, 1, n+1){
        vector<int> used(n+1, 0);
        cnt = 0;
        dfs(i, used);
        res += cnt;
    }
    cout << res << endl;
}