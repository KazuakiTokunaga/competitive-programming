#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define all(x) (x).begin(),(x).end()

namespace geometry {
    // Point : 複素数型を位置ベクトルとして扱う
    // 実軸(real)をx軸、挙軸(imag)をy軸として見る
    using D = long double;
    using Point = complex<D>;
    const D EPS = 1e-7;
    const D PI = acosl(-1);

    inline bool equal(const D &a, const D &b) { return fabs(a - b) < EPS; }

    // 内積(dot product) : a・b = |a||b|cosΘ
    D dot(const Point &a, const Point &b) {
        return (a.real() * b.real() + a.imag() * b.imag());
    }

    // 外積(cross product) : a×b = |a||b|sinΘ
    D cross(const Point &a, const Point &b) {
        return (a.real() * b.imag() - a.imag() * b.real());
    }

    // 点の回転方向
    // 点a, b, cの位置関係について(aが基準点)
    int ccw(const Point &a, Point b, Point c) {
        b -= a, c -= a;
        // 点a, b, c が
        // 反時計回りの時、
        if(cross(b, c) > EPS) return 1;
        // 時計回りの時、
        if(cross(b, c) < -EPS) return -1;
        // c, a, bがこの順番で同一直線上にある時、
        if(dot(b, c) < 0) return 2;
        // a, b, cがこの順番で同一直線上にある場合、
        if(norm(b) < norm(c)) return -2;
        // cが線分ab上にある場合、
        return 0;
    }

    // 凸多角形かどうか
    bool isConvex(const vector<Point> &p) {
        int n = p.size();
        int now, pre, nxt;
        for(int i = 0; i < n; i++) {
            pre = (i - 1 + n) % n;
            nxt = (i + 1) % n;
            now = i;
            if(ccw(p[pre], p[now], p[nxt]) == -1) return false;
        }
        return true;
    }

} // namespace geometry

using namespace geometry;

int main() {
    vector<Point> points;
    rep(i, 0, 4){
        int x, y;
        cin >> x >> y;
        points.push_back(Point(x, y));
    }

    if (isConvex(points)) cout << "Yes" << endl;
    else cout << "No" << endl;
}