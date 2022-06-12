#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    rep(i, 0, n) cin >> a[i];
    
    int res = 0;
    rep(i, 0, n){
        int mini = a[i];
        rep(j, i, n){
            if (a[j] < mini){
                mini = a[j];
            }
            res = max(res, (j - i + 1) * mini);
        }
    }
    cout << res << endl;
}