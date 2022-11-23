#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define all(x) (x).begin(),(x).end()

int main() {
    int N; ll P, Q, R;
    cin >> N >> P >> Q >> R;
    
    vector<ll> A(N), accum(N+1, 0);
    rep(i, 0, N) {
        cin >> A[i];
        accum[i+1] = A[i] + accum[i];
    }

    rep(x, 1, N){
        ll s = accum[x-1];
        int y_id = lower_bound(all(accum), s+P) - accum.begin();
        if (y_id >= N+1 or accum[y_id] != s+P) continue;

        int z_id = lower_bound(all(accum), s+P+Q) - accum.begin();
        if (z_id >= N+1 or accum[z_id] != s+P+Q) continue;

        int w_id = lower_bound(all(accum), s+P+Q+R) - accum.begin();
        if (w_id >= N+1 or accum[w_id] != s+P+Q+R) continue;

        cout << "Yes" << endl;
        return 0;
    }
    cout << "No" << endl;

}