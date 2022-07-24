// いもす法のような気持ちで解く

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<ll, ll>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define all(x) (x).begin(),(x).end()
const int MOD = 998244353;

int main() {
    int N, K;
    cin >> N >> K;

    vector<pii> intervals;
    rep(i, 0, K){
        int l, r;
        cin >> l >> r;
        intervals.push_back({l, r});
    }

    vector<ll> cnt(N, 0);
    ll cur = 1;
    rep(i, 0, N){
        cur += cnt[i];
        for (pii p: intervals) {
            ll l = p.first, r = p.second;
            if (i+l < N){
                cnt[i+l] += cur;
                cnt[i+l] %= MOD;
            }
            if (i+r+1 < N) {
                cnt[i+r+1] -= cur;
                cnt[i+r+1] %= MOD;
            }
        }
    }

    cout << cnt[N-1] << endl;
}