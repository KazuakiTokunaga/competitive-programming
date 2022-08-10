#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<ll, ll>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define all(x) (x).begin(),(x).end()

int main() {
    ll N, L, R;
    cin >> N >> L >> R;
    
    vector<ll> A(N);
    rep(i, 0, N) cin >> A[i];

    vector<ll> accum(N);
    partial_sum(A.begin(), A.end(), accum.begin());

    // 何も変えないとき
    ll res = accum[N-1];

    // i番目までをLに変えたときに、どれだけ小さくなるか
    vector<pii> diff;
    diff.push_back({0, -1});
    rep(i, 0, N){
        diff.push_back({accum[i] - L * (i+1), i+1});
    }
    sort(all(diff));

    // 右からRに変える位置で全探索
    pii p = diff.back(); diff.pop_back();
    res = min(res, res - p.first); // Rには1つも変えないとき

    ll total = res;
    rrep(i, N-1, 0){
        if (p.second >= i){
            total += p.first;
            while (p.second >= i){
                p = diff.back(); diff.pop_back();
            }
            total -= p.first;
        }
        total += R - A[i];
        res = min(res, total);
    }
    cout << res << endl;
}