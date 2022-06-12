#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
using Graph = vector<vector<int>>;

vector<int> res;
queue<int> q;
bool bfs(Graph &G, int cur){
    for (int e: G[cur]) {
        if (res[e] != 0) continue;
        res[e] = cur;
        q.push(e);
    }

    while (!q.empty()){
        int e = q.front();
        q.pop();
        bfs(G, e);
    }

    return true;
}

int main() {
    int n,m;
    cin >> n >> m;

    Graph G(n+1);
    res.assign(n+1, 0);
    res[0] = 1; res[1] = 1;
    for (int i = 0; i < m; i++) {
        int a,b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    
    bfs(G, 1);
    
    int mini = *min_element(res.begin(), res.end()); 
    if (mini == 0) {
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;;
        rep(i, 2, n+1){
            cout << res[i] << endl;
        }
    }

}