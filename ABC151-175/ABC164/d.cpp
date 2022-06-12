#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)

int main() {
    string s;
    cin >> s;
    int size = s.size();

    vector<ll> count(2019, 0);
    count[0] = 1;
    ll p = 1;
    ll ans = 0;
    int tot = 0;
    rrep(i, size-1, 0){
        tot = (tot + int(s[i]-'0') * p) % 2019;
        ans += count[tot];

        p *= 10;
        p %= 2019;
        count[tot]++;
    }

    cout << ans << endl;
}