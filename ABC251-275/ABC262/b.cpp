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
    
    vector<vector<int>> dist(N, vector<int>(N, 0));
    rep(i, 0, M){
        int u, v;
        cin >> u >> v;
        u--; v--;
        dist[u][v] = 1;
        dist[v][u] = 1;
    }

    int res = 0;
    rep(i, 0, N-2){
        rep(j, i+1, N-1){
            rep(k, j+1, N){
                if (dist[i][j] and dist[j][k] and dist[k][i]) res++;   
            }
        }
    }
    cout << res << endl;
}