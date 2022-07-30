#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define all(x) (x).begin(),(x).end()

int main() {
    int H, W, R, C;
    cin >> H >> W >> R >> C;

    int res = 4;
    if (H == 1) res--;
    if (W == 1) res--;
    if (R == 1 or R == H) res--;
    if (C == 1 or C == W) res--;
    cout << res << endl;
}