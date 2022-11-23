#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define all(x) (x).begin(),(x).end()

int N, Q;
vector<int> X;
vector<int> used;
vector<vector<int>> Largest;
vector<vector<int>> graph;

vector<int> dfs(int c){
    used[c] = 1;

    bool leaf = true;
    vector<int> res = {X[c]};
    for (int nxt: graph[c]) {
        if (used[nxt]) continue;

        leaf = false;
        vector<int> res_base = dfs(nxt);

        rep(i, 0, res_base.size()){
            res.push_back(res_base[i]);
        }
    }

    // 葉の場合
    if (leaf){
        res = {X[c]};
        Largest[c] = res;
        return res;
    }

    // cout << c << ": ";
    // for (auto i: res) {cout << i << ' ';} cout << endl;
    
    sort(all(res), greater<int>());

    vector<int> res_trimmed;
    int cnt = min(20, (int)res.size());
    rep(i, 0, cnt){
        res_trimmed.push_back(res[i]);
    }
    Largest[c] = res_trimmed;
    return res_trimmed;
}

int main() {
    cin >> N >> Q;
    
    X.assign(N, 0);
    rep(i, 0, N) cin >> X[i];
    
    graph.assign(N, vector<int>());
    rep(i, 0, N-1){
        int a, b;
        cin >> a >> b; a--; b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    used.assign(N, 0);
    Largest.assign(N, vector<int>());
    dfs(0);

    rep(i, 0, Q){
        int v, k;
        cin >> v >> k; v--; k--;
        
        // for (auto j: Largest[v]) {cout << j << ' ';} cout << endl;
        cout << Largest[v][k] << endl;
    }
}