// 数列の長さをNとすると、O(NlogN)で解ける

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define all(x) (x).begin(),(x).end()
const int INF = pow(10, 9) + 7;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    rep(i, 0, n) cin >> a[i];
    
    
    vector<int> dp(n+1, INF);
    rep(i, 0, n){
        auto iter = lower_bound(all(dp), a[i]);
        *iter = a[i];
    }

    int res = lower_bound(all(dp), INF) - dp.begin();
    cout << res << endl;
}

/*
5
4 2 3 1 5

10
8 2 1 3 5 9 2 4 6 12
*/