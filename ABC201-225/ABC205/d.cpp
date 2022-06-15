#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)

vector<ll> a;
bool check(ll mid, ll k){
    auto iter = upper_bound(a.begin(), a.end(), mid);
    int cnt = iter - a.begin();
    if (k + cnt > mid) return true;
    else return false;
}

int main() {
    int n, q;
    cin >> n >> q;
    
    a.assign(n, 0);
    rep(i, 0, n) cin >> a[i];
    
    rep(i, 0, q){
        ll k;
        cin >> k;

        ll left = 0, right = 1LL << 60;
        ll mid = (left + right) / 2;
        while (mid > left){
            if (check(mid, k)) left = mid;
            else right = mid;
            mid = (left + right) / 2;
            cout << left << " " << right << " " << mid << endl;
        }
        cout << left << endl;
    }
}