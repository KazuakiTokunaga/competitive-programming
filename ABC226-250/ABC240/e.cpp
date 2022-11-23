#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define all(x) (x).begin(),(x).end()
const int INF = pow(10, 9) + 7;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false;}
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return true; } return false;}

int N;
int counter = 1;
vector<vector<int>> graph;
vector<int> used;
vector<pii> intervals;

pii dfs(int c){
    used[c] = 1;

    bool leaf = true;
    int mi = INF, ma = 0;
    for (int nxt: graph[c]) {
        // 到達済みの頂点
        if (used[nxt]) continue;

        leaf = false;
        pii p = dfs(nxt);
        chmin(mi, p.first);
        chmax(ma, p.second);
    }

    // 葉に到達
    if (leaf){
        intervals[c] = {counter, counter};
        counter++;
        return intervals[c];
    }

    intervals[c] = {mi, ma};
    return intervals[c];
}


int main() {    
    cin >> N;

    graph.assign(N+1, vector<int>());
    used.assign(N+1, 0);
    intervals.assign(N+1, pii());
    rep(i, 0, N-1){
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    dfs(1);
    rep(i, 1, N+1){
        pii p = intervals[i];
        cout << p.first << " " << p.second << endl;
    }
}