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

    int total = 0;
    rep(i, 0, n){
        total ^= a[i];
    }

    rep(i, 0, n){
        int res = total ^ a[i];
        cout << res << endl;
    }
}