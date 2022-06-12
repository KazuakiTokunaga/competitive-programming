#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)

int main() {
    int n, m;
    cin >> n >> m;

    int mini = 0, maxi = pow(10,6);
    
    rep(i, 0, m){
        int l, r;
        cin >> l >> r;
        mini = max(mini, l);
        maxi = min(r, maxi);
    }
    cout << max((maxi - mini) + 1, 0) << endl;
}