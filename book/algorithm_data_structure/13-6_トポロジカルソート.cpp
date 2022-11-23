// 計算量O(V+E)

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define all(x) (x).begin(),(x).end()
using Graph = vector<vector<int>>;

vector<bool> seen;
vector<int> order;
void rec(const Graph &G, int v){
    seen[v] = true;
    for (auto next_v: G[v]) {
        if (seen[next_v]) continue;
        rec(G, next_v);
    }

    order.push_back(v);
}

int main() {
    int n, m;
    cin >> n >> m;
    Graph G(n);

    rep(i, 0, m){
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
    }

    seen.assign(n, false);
    order.clear();
    rep(v, 0, n){
        if (seen[v]) continue;
        rec(G, v);
    }
    reverse(all(order));

    for (auto i: order) {cout << i << ' ';} cout << endl;

}

/*
8 12
4 2
4 6
4 1
1 6
1 3
6 7
2 7
3 7
3 0
7 0
2 5
0 5
*/