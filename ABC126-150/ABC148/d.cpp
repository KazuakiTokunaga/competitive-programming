#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)

int main() {
    int n;
    cin >> n;
 
    int cur = 1;
    int res = 0;
    rep(i, 0, n){
        int a;
        cin >> a;

        if (a == cur) cur++;
        else res++;
    }

    if (cur == 1) cout << -1 << endl;
    else cout << res << endl;
}