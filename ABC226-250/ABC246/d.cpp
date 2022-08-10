#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define all(x) (x).begin(),(x).end()

ll N;
bool check(ll a, ll mid){
    if ((a+mid) * (a*a + mid*mid) >= N) return true;
    else return false;
}


int main() {
    cin >> N;

    ll res = 2LL << 60;
    rep(a, 0, 1000100){
        ll left = -1;
        ll right = 1000100;
        while (right - left > 1){
            ll mid = (left + right) / 2;
            if (check(a, mid)) right = mid;
            else left = mid;
        }
        ll t = (a + right) * (a*a + right*right);
        res = min(res, t);
    }

    cout << res << endl;
}