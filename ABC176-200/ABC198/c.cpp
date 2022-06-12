#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)

int main() {
    int r, x, y;
    cin >> r >> x >> y;
    
    ld d = pow(pow(x, 2) + pow(y, 2), 0.5);
    if (d < r) cout << 2 << endl;
    else cout << (int)ceil(d / r) << endl;
}