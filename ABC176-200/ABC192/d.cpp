#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
const ll INF = 1LL << 60;

ll power(ll x, ll n) {
    ll ret = 1;
    while (n > 0) {
        if (n & 1) {
            if ((double)ret * x > 1e18) return INF;
            ret *= x;
        }
        n >>= 1;  // n を1bit 左にずらす
        if (n <= 0) break;
        if ((double) x * x > 1e18) return INF;
        x *= x;
    }
    return ret;
}

ll calculate(ll d, string s){
    ll result = 0;
    rep(i, 0, s.size()){
        if (power(d, (int)s.size() - 1 - i) > 1e18){
            return 1LL << 60;
        }
        result += int(s[i] - '0') * power(d, (int)s.size() - 1 - i);
    }
    return result;
}
 
int main() {
    string s; ll m;
    cin >> s >> m;
 
    if (s.size() == 1){
        if (stoi(s) <= m) cout << 1 << endl;
        else cout << 0 << endl;
        return 0;
    }
 
    int d = 0;
    rep(i, 0, s.size()){
        d = max(d, int(s[i]-'0'));
    }
    d++;
    
    if (calculate(d, s) > m){
        cout << 0 << endl;
        return 0;
    }
 
    ll max_d = 1LL << 60;
    ll min_d = d;
    ll cur_d = max_d;
    while (cur_d != min_d){
        ll result = calculate(cur_d, s);
        if (result > m){
            max_d = cur_d;
            cur_d = (max_d + min_d) / 2;
        } else {
            min_d = cur_d;
            cur_d = (max_d + min_d) / 2;
        }
    }
    cout << cur_d - d + 1 << endl;
}