#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define all(x) (x).begin(),(x).end()
const int MOD = pow(10, 9) + 7;

int n, k; ll res = 1;
vector<int> cnt;
vector<vector<int>> graph;

bool dfs(int v, int p, int sib_cnt){
    ll usable = k - 1 - sib_cnt - 1; // 候補になる色の数
    if (p == 1) usable++; // 親が根のとき祖父がいないので
    if (v == 1) usable++; // 根のとき

    res *= usable; res %= MOD;

    vector<int> sibs = graph[v];
    int next_sib_cnt = 0;
    for (int i: sibs) {
        if (i == p) continue; // 親には戻らない
        dfs(i, v, next_sib_cnt);
        next_sib_cnt++;
    }
    return true;
}


int main() {
    cin >> n >> k;

    graph.assign(n+1, vector<int>());
    rep(i, 0, n-1){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    dfs(1,1,0);
    cout << res << endl;
}