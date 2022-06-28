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

    vector<int> H(N);
    rep(i, 0, N) cin >> H[i];
    sort(all(H));

    vector<int> W(M);
    rep(i, 0, M) cin >> W[i];

    vector<ll> Odds, Evens;
    rep(i, 0, N){
        if (i % 2 == 1) {
            Odds.push_back(H[i]);
            Evens.push_back(0);
        }
        if (i % 2 == 0) {
            Odds.push_back(0);
            Evens.push_back(H[i]);
        }
    }
    vector<ll> Odds_accum(N), Evens_accum(N);
    partial_sum(Odds.begin(), Odds.end(), Odds_accum.begin());
    partial_sum(Evens.begin(), Evens.end(), Evens_accum.begin());


    ll res = 1LL << 60;
    rep(i, 0, M){
        int w = W[i];
        int idx = lower_bound(all(H), w) - H.begin(); // 挿入できるindex

        ll a = (idx>0 ? Evens_accum[idx-1]: 0);
        ll b = (idx>0 ? Odds_accum[idx-1]: 0);
        ll c = Evens_accum.back() - a;
        ll d = Odds_accum.back() - b;
        ll res0 = b - a + c - d;
        
        if (idx % 2 == 0) res0 -= w;
        else res0 += w;

        res = min(res, res0);
    }

    cout << res << endl;
}