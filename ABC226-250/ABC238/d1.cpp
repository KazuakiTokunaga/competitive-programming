#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define all(x) (x).begin(),(x).end()

// 実装は公式解説に近い
// https://atcoder.jp/contests/abc238/editorial/3374
int main() {
    int T;
    cin >> T;
    
    rep(i, 0, T){
        ll a, s;
        cin >> a >> s;

        bool check = true;
        ll p = s - 2 * a; // p = x XOR y
        if (p < 0) check = false;

        // a = x AND y, p = x XOR y に解があるかどうかを調べる
        rep(j, 0, 60){
            int a1 = (a >> j) & 1;
            int p1 = (p >> j) & 1;

            if (p1 and a1) {check = false; break;}
        }

        if (check) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}