#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define all(x) (x).begin(),(x).end()

vector<vector<int>> Tree;
vector<pii> Edge;
vector<ll> Point, Res;
vector<int> Seen, Parents;
int N;
ll Base = 0;

// 各頂点の親を記録する
void dfs0(int i){
    for (int e: Tree[i]) {
        if (Parents[e] != -1) continue;
        Parents[e] = i;
        dfs0(e);
    }
}

// 得点を計算する
void dfs1(int i, ll cur){
    cur += Point[i];
    Res[i] = cur;
    Seen[i] = 1;

    for (int e: Tree[i]) {
        if (Seen[e]) continue;
        dfs1(e, cur);
    }
}

int main() {
    cin >> N;
    Tree.assign(N, vector<int>());
    rep(i, 0, N-1){
        int a, b;
        cin >> a >> b; a--; b--;
        
        Edge.push_back({a, b});
        Tree[a].push_back(b);
        Tree[b].push_back(a);
    }

    Parents.assign(N, -1);
    Parents[0] = 0;
    dfs0(0);

    Point.assign(N, 0);
    int Q; cin >> Q;
    rep(i, 0, Q){
        int t, e, x;
        cin >> t >> e >> x; e--;
        
        pii edge = Edge[e];
        int from = edge.first, notReach = edge.second;
        if (t == 2) swap(from, notReach);

        if (Parents[from] == notReach){
            Point[from] += x;
        } else {
            Base += x;
            Point[notReach] -= x;
        }
    }
    
    Res.assign(N, 0);
    Seen.assign(N, 0);
    dfs1(0, 0);

    rep(i, 0, N){
        cout << Res[i] + Base << endl;
    }
}