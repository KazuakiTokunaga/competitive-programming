#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define all(x) (x).begin(),(x).end()

int main() {
    int N, M;
    cin >> N >> M;
    
    vector<vector<int>> graph(N);
    rep(i, 0, M){
        int a, b;
        cin >> a >> b; a--; b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    vector<vector<int>> dist(N, vector<int>(4, 0));

    rep(i, 0, N){
        map<int,int> used;
        used[i] = 1;

        queue<pii> q;
        q.push({i, 0}); // 頂点iとの距離は0;
        
        while (!q.empty()){
            pii p = q.front(); q.pop();
            int v, d;
            tie(v, d) = p;
            dist[i][d] += v+1;

            if (d <= 2){
                for (int nxt: graph[v]) {
                    if (used[nxt]) continue;
                    
                    used[nxt] = 1;
                    q.push({nxt, d+1});
                }
            }
        }
    }

    int Q; 
    cin >> Q;

    // for (auto i: dist[0]) {cout << i << ' ';} cout << endl;
    
    rep(i, 0, Q){
        int x, k;
        cin >> x >> k;

        int res = 0;
        rep(j, 0, k+1){
            res += dist[x-1][j];
        }

        cout << res << endl;
    }
}