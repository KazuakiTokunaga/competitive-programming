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
    
    vector<ll> A(N);
    rep(i, 0, N) cin >> A[i];

    vector<ll> accum(N);
    partial_sum(A.begin(), A.end(), accum.begin());

    ll s = 0;
    rep(i, 0, M){
        s += (i+1) * A[i];
    }

    ll res = s;
    rep(i, M, N){
        s += M * A[i];
        s -= A[i-M];
        s -= accum[i-1] - accum[i-M];
        res = max(res, s);
    }
    cout << res << endl;
    

}