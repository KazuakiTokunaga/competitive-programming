#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)

int main() {
    int n;
    cin >> n;

    ll aoki = 0;
    vector<ll> takahashi;
    rep(i, 0, n){
        ll a, b;
        cin >> a >> b;
        
        aoki += a;
        takahashi.push_back(2 *a + b);
    }

    sort(takahashi.begin(), takahashi.end());
    
    ll point = 0;
    ll cnt = 0;
    while (point <= aoki){
        ll a = takahashi.back(); takahashi.pop_back();
        point += a;
        cnt++;
    }

    cout << cnt << endl;

}