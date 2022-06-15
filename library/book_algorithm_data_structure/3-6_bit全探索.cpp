// bit全探索

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)


int main() {
    int n, w;
    cin >> n >> w;

    vector<int> a(n);
    rep(i, 0, n) cin >> a[i];
    
    bool exist = false;

    // 2^N通りの部分集合全体を走査
    rep(bit, 0, 1<<n){
        int sum = 0;

        // a[i]が部分集合に含まれているかどうかを判定
        rep(i, 0, n){
            if (bit & 1 << i){
                sum += a[i];
            }
        }

        if (sum == w) exist = true;
    }
    
    if (exist) cout << "Yes" << endl; else cout << "No" << endl;
}