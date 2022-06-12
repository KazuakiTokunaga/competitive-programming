#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using ld = long double;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)

int main() {
    int n, x0, y0, x4, y4;
    cin >> n >> x0 >> y0 >> x4 >> y4;

    ld o_x = (ld)(x0 + x4) / 2;
    ld o_y = (ld)(y0 + y4) / 2;

    ld pi = M_PI;
    ld theta = 2 * pi / n;

    ld x_t = x0 - o_x;
    ld y_t = y0 - o_y;

    ld X_t = x_t * cos(theta) - y_t * sin(theta);
    ld Y_t = x_t * sin(theta) + y_t * cos(theta);

    ld x1 = X_t + o_x;
    ld y1 = Y_t + o_y;
    
    cout << fixed << setprecision(15);
    cout << x1 << " " << y1 << endl;
}