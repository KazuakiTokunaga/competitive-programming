#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define all(x) (x).begin(),(x).end()

// https://atcoder.jp/contests/abc242/editorial/3520
string S;
ll f(ll t, ll k){
    if (t == 0) return ll(S[k]-'A');
    if (k == 0) return ll(S[0]-'A') + t;

    return f(t-1, k/2) + k%2 + 1;
}

int main() {
    cin >> S;

    int Q;
    cin >> Q;
    rep(i, 0, Q){
        ll t, k; cin >> t >> k;
        ll res = f(t, k-1);
        // cout << "res: " << res << endl;
        cout << char(res % 3 + 'A') << endl;
    }
}