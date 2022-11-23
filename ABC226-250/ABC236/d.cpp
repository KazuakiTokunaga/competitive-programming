#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define all(x) (x).begin(),(x).end()

int N;
ll res;
vector<pii> pairs;
vector<int> used(20, 0);
vector<vector<ll>> A(20, vector<ll>(20, 0));

void get_point(){
    ll score = 0;
    for (pii p: pairs) {
        auto[i, j] = p;
        score ^= A[i][j];
    }
    res = max(res, score);
}

void dfs(int cur, int cnt){
    if (cnt == N){
        get_point();
        return;
    }
    while (used[cur]) cur++;

    rep(i, cur+1, 2*N){
        if (used[i]) continue;

        used[i] = 1;
        pairs.push_back({cur, i});
        dfs(cur+1, cnt+1);
        pairs.pop_back();
        used[i] = 0;
    }
}

int main() {
    cin >> N;
    rep(i, 0,2*N-1) rep(j, i+1, 2*N) cin >> A[i][j];

    dfs(0, 0);
    cout << res << endl;
}