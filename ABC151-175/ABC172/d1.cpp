#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)

// 公式解説O(N)
// https://img.atcoder.jp/abc172/editorial.pdf

int main() {
    int n;
    cin >> n;
    
    ll res1 = 0;
    rep(j, 1, n+1){
        ll maxi = n / j;
        ll s = j * (1 + maxi) * maxi / 2;
        res1 += s;
    }
    cout << res1 << endl;

    
}