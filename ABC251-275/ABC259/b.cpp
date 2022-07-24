#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define all(x) (x).begin(),(x).end()

using D = long double;
using Point = complex<D>;
const D PI = acosl(-1);

Point rotate(const Point &p, const D &theta) {
    return Point(cos(theta) * p.real() - sin(theta) * p.imag(),
                    sin(theta) * p.real() + cos(theta) * p.imag());
}

// 度->ラジアン
D degreeToRadian(const D &degree) { return degree * PI / 180.0; }

int main() {
    int a, b, d;
    cin >> a >> b >> d;
    
    Point x = {a, b};
    Point x1 = rotate(x, degreeToRadian(d));
    
    cout << fixed << setprecision(15);
    cout << x1.real() << " " << x1.imag() << endl;
}