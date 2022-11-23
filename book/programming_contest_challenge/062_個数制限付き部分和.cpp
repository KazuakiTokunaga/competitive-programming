// i番目まででjを作る際に余る最大のi番目の個数でDPしていく
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define all(x) (x).begin(),(x).end()

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    rep(i, 0, n) cin >> a[i];
    
    vector<int> m(n);
    rep(i, 0, n) cin >> m[i];
    
    vector<int> dp(k+1, -1);
    dp[0] = 0;

    rep(i, 0, n){
        rep(j, 0, k+1){
            if (dp[j] >= 0) {
                dp[j] = m[i];
            } else if (j < a[i] or dp[j-a[i]] <= 0){
                dp[j] = -1;
            } else {
                dp[j] = dp[j-a[i]] -1;
            }
        }
    }
    if (dp[k] >= 0) cout << "Yes" << endl;
    else cout << "No" << endl;
}

/*
3 17
3 5 8
3 2 2
*/