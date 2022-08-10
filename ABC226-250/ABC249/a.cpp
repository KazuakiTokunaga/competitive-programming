#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define all(x) (x).begin(),(x).end()

ll res = 0;
int N;
vector<ll> A(200100, 0);
vector<ll> cnt(200100, 0);
vector<ll> memo(200100, -1);

void enum_counter(ll n) {
    if (memo[n] >= 0) {res += memo[n]; return;}

    ll cur = 0;
    for (ll i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            if (i != n/i) cur += cnt[i] * cnt[n/i] * 2;
            else cur += cnt[i] * (cnt[i]-1) + cnt[i];
        }
    }
    memo[n] = cur;
    res += cur;
}

int main() {
    cin >> N;
    rep(i, 0, N) {cin >> A[i]; cnt[A[i]]++;}
    rep(i, 0, N) enum_counter(A[i]);

    cout << res << endl;
}