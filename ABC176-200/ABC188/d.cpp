#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)

int main() {
    ll n, C;
    cin >> n >> C;

    vector<pii> q; 
    rep(i, 0, n){
        int a, b, c;
        cin >> a >> b >> c;
        q.push_back({a,c});
        q.push_back({b+1, -1 * c});
    }
    sort(q.begin(), q.end());
    int last_days = q.back().first;
    q.push_back({last_days+1, 0});
    reverse(q.begin(), q.end());
    

    ll res = 0;    
    ll cur_days = 0;
    ll cur_price = 0;
    while (!q.empty()){
        pii p = q.back(); q.pop_back();

        // cout << "item:" << " " << p.first << " " << p.second << endl;
        
        int elapsed_days = p.first - cur_days;
        res += (ll)elapsed_days * min(cur_price, C);
        
        // cout << "days & cost:" << " " << elapsed_days << " " << cur_price << endl;
        cur_days += elapsed_days;
        cur_price += p.second;
    }

    cout << res << endl;
}