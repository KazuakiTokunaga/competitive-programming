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
    
    vector<ll> S(N-1);
    rep(i, 0, N-1) cin >> S[i];
    
    vector<ll> X(M);
    rep(i, 0, M) cin >> X[i];
    

    vector<ll> base;
    base.push_back(0);
    rep(i, 0, N-1){
        base.push_back(S[i] - base[i]);
    }
    
    vector<ll> base_odds;
    vector<ll> base_evens;
    rep(i, 0, N){
        if (i % 2) base_odds.push_back(base[i]);
        else base_evens.push_back(base[i]);        
    }

    map<ll, ll> cnt;
    for (ll i: base_odds) {
        for (ll j: X) {
            cnt[j - i]++;
        }
    }
    for (ll i: base_evens) {
        for (ll j: X) {
            cnt[i - j]++;
        }
    }

    ll res = 0;
    for (ll i: base_odds) {
        for (ll j: X) {
            res = max(res, cnt[j-i]);
        }
    }
    for (ll i: base_evens) {
        for (ll j: X) {
            res = max(res, cnt[i-j]);
        }
    }
    cout << res << endl;

}