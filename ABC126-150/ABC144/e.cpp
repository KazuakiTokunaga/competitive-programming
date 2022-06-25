#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define all(x) (x).begin(),(x).end()

ll n, k;
vector<ll> A, F;

bool check(ll t){
    ll cnt = 0;
    rep(i, 0, n){
        ll a = A[i]; ll f = F[i];
        if (a * f <= t) continue;
        else {
            ll lb = t / f;
            cnt += a - lb;
            if (cnt > k) return false;
        }
    }
    return true;
}

int main() {
    cin >> n >> k;
    rep(i, 0, n) {
        ll a; cin >> a;
        A.push_back(a);
    }
    sort(all(A));

    rep(i, 0, n){
        ll f; cin >> f;
        F.push_back(f);
    }
    sort(all(F), greater<ll>());

    ll left = -1; ll right = 1LL << 60;
    while (right - left > 1){
        ll mid = (left + right) / 2;
        if (check(mid)) right = mid;
        else left = mid;
    }
    cout << right << endl;
}