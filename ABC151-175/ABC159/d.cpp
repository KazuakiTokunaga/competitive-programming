#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)

int main() {
    int n;
    cin >> n;
    
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    
    vector<int> count(n+1, 0);
    rep(i, 0, n){
        count[a[i]]++;
    }

    ll total = 0;
    for (int i: count) {
        total += (ll)i * (i-1) / 2;
    }

    for (int i: a) {
        ll c = count[i];
        cout << total - (c * (c-1) / 2) + ((c-1) * (c-2) / 2) << endl;
    }
}