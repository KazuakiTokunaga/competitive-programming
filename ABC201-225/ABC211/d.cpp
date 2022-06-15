#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
const int MOD = pow(10, 9) + 7;
vector<vector<int>> graph;
vector<int> dist;
vector<int> path_cnt;
queue<pii> q;
int n, m;

bool bfs(int i, int cur){

    for (int j: graph[i]) {
        if (dist[j] == -1){
            dist[j] = cur+1;
            path_cnt[j] = path_cnt[i];
        } else if (dist[j] == cur+1){
            path_cnt[j] += path_cnt[i];
            path_cnt[j] %= MOD;
            continue;
        } else {
            continue;
        }
        pii p = {j, cur+1};
        q.push(p);
    }

    if (!q.empty()){
        pii e = q.front(); q.pop();
        bfs(e.first, e.second);
    }

    return true;
}

int main() {
    cin >> n >> m;

    graph.assign(n+1, vector<int>());
    path_cnt.assign(n+1, 0);
    dist.assign(n+1, -1);
    rep(i, 0, m){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    dist[1] = 0;
    path_cnt[1] = 1;
    bfs(1, 0); 
    
    cout << path_cnt[n] << endl;
}