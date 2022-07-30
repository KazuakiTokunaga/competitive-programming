#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define all(x) (x).begin(),(x).end()

int main() {
    int N, Q;
    cin >> N >> Q;
    
    vector<ll> A(N);
    rep(i, 0, N) cin >> A[i];

    sort(all(A));

    vector<ll> Accum(N+1); Accum[0] = 0;
    partial_sum(A.begin(), A.end(), Accum.begin()+1);

    rep(i, 0, Q){
        ll X; cin >> X;
        ll cnt = 0;

        int idx = lower_bound(all(A), X) - A.begin();
        
        cnt += idx * X - Accum[idx];
        cnt += Accum[N] - Accum[idx] - (N-idx) * X;
        cout << cnt << endl;
    }
}