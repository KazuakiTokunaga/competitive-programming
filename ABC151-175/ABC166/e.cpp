#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)

int main() {
    int n;
    cin >> n;
    
    ll res = 0;
    map<int, int> mp;
    vector<int> a(n);
    rep(i, 0, n){
        cin >> a[i];
        res += mp[(i+1) - a[i]];
        mp[a[i] + (i+1)] += 1;
    }

    cout << res << endl;

}