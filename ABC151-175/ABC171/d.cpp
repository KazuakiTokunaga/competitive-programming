#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)

int main() {
    int n, q;
    cin >> n;

    ll res = 0;
    vector<int> cnt(100100, 0);
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        cnt[a]++;
        res += a;
    }
    
    cin >> q;
    rep(i, 0, q){
        int b, c;
        cin >> b >> c;

        int count = cnt[b];

        res -= (ll)count * b;
        res += (ll)count * c;
        cout << res << endl;

        cnt[c] += count;
        cnt[b] = 0;
    }
}