#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)

// ユーザー解説O(NlogN)
int main() {
    int n;
    cin >> n;
    
    ll res = 0;
    rep(i, 1, n+1){
        ll t = i;
        while (t <= n){
            res += t;
            t += i;
        }
    }
    cout << res << endl;
}