#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define all(x) (x).begin(),(x).end()

int n;
vector<vector<int>> A;
vector<vector<int>> Id;
vector<vector<int>> path;
vector<int> dp;
vector<int> seen;
vector<int> calculating;

int getId(int i, int j){
    if (i>j) swap(i, j);
    return Id[i][j];
}

int dfs(int v){
    // 計算途中でループした
    if (calculating[v]) return -1;
    
    // 探索済み
    if (seen[v]) return dp[v];

    seen[v] = true;
    calculating[v] = true;
    dp[v] = 1;
    
    for (int nxt: path[v]) {
        int d = dfs(nxt);
        if (d == -1) return -1;
        dp[v] = max(dp[v], d+1);
    }
    calculating[v] = false;        

    return dp[v];
}

int main(){
    cin >> n;

    A.assign(n, vector<int>(n-1));
    Id.assign(n, vector<int>(n));
    int v = 0;
    rep(i, 0, n){
        rep(j, 0, n-1){
            int a; cin >> a; a--;
            A[i][j] = a;
            if (i < a) Id[i][a] = v++;
        }
    }

    path.assign(v, vector<int>());
    rep(i, 0, n){
        rep(j, 0, n-2){
            int a, v, a1, v1;
            a = A[i][j]; a1 = A[i][j+1];
            v = getId(i, a); v1 = getId(i, a1);
            path[v].push_back(v1);
        }
    }

    dp.assign(v, -1);
    seen.assign(v, false);
    calculating.assign(v, false);
    int res = 0;
    rep(i, 0, v){
        int r = dfs(i);
        if (r == -1) {res = -1; break;}
        res = max(res, r);
    }
    
    cout << res << endl;
}

// この説明を参考にする
// https://scrapbox.io/esaka-sandbox/AtCoder_Beginner_Contest_139_-_E_-_League(%E3%82%B0%E3%83%A9%E3%83%95%E3%82%92%E4%BD%BF%E3%81%86)