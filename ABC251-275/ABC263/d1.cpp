#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define all(x) (x).begin(),(x).end()

// https://atcoder.jp/contests/abc263/editorial/4549
int main() {
    ll N, L, R;
    cin >> N >> L >> R;
    
    vector<ll> A(N);
    rep(i, 0, N) cin >> A[i];
    
    vector<ll> F(N+1), G(N+1);
    F[0] = 0; G[N] = 0;

    rep(i, 0, N){
        ll t1 = F[i] + A[i]; // 置き換えない
        ll t2 = L * (i+1); // 置き換える
        F[i+1] = min(t1, t2);
    }
    rrep(i, N-1, 0){
        ll t1 = G[i+1] + A[i];
        ll t2 = R * (N - i);
        G[i] = min(t1, t2);
    }

    ll res = 2LL << 60;
    rep(i, 0, N+1){
        res = min(res, F[i]+G[i]);
    }
    cout << res << endl;
}