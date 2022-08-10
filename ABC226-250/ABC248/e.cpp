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
    const D EPS = 1e-10;
    const D PI = acosl(-1);

    inline bool equal(const D &a, const D &b) { return fabs(a - b) < EPS; }

    // 単位ベクトル(unit vector)を求める
    Point unitVector(const Point &a) { return a / abs(a); }

    // 内積(dot product) : a・b = |a||b|cosΘ
    D dot(const Point &a, const Point &b) {
        return (a.real() * b.real() + a.imag() * b.imag());
    }

    // 外積(cross product) : a×b = |a||b|sinΘ
    D cross(const Point &a, const Point &b) {
        return (a.real() * b.imag() - a.imag() * b.real());
    }

    // Line : 直線を表す構造体
    // b - a で直線・線分を表せる
    struct Line {
        Point a, b;
        Line() = default;
        Line(Point a, Point b) : a(a), b(b) {}
        // Ax+By=C
        Line(D A, D B, D C) {
            if(equal(A, 0)) {
                a = Point(0, C / B), b = Point(1, C / B);
            } else if(equal(B, 0)) {
                b = Point(C / A, 0), b = Point(C / A, 1);
            } else {
                a = Point(0, C / B), b = Point(C / A, 0);
            }
        }
    };

    // 2直線の直交判定 : a⊥b <=> dot(a, b) = 0
    bool isOrthogonal(const Line &a, const Line &b) {
        return equal(dot(a.b - a.a, b.b - b.a), 0);
    }
    // 2直線の平行判定 : a//b <=> cross(a, b) = 0
    bool isParallel(const Line &a, const Line &b) {
        return equal(cross(a.b - a.a, b.b - b.a), 0);
    }

    // 点cが直線ab上にあるか
    bool isPointOnLine(const Point &a, const Point &b, const Point &c) {
        return isParallel(Line(a, b), Line(a, c));
    }

    // 直線lと点pの距離を求める
    D distanceBetweenLineAndPoint(const Line &l, const Point &p) {
        return abs(cross(l.b - l.a, p - l.a)) / abs(l.b - l.a);
    }

    // 直線s, tの交点の計算
    Point crossPoint(const Line &s, const Line &t) {
        D d1 = cross(s.b - s.a, t.b - t.a);
        D d2 = cross(s.b - s.a, s.b - t.a);
        if(equal(abs(d1), 0) && equal(abs(d2), 0)) return t.a;
        return t.a + (t.b - t.a) * (d2 / d1);
    }

} // namespace geometry

using namespace geometry;

int main() {
    int N, K;
    cin >> N >> K;
    
    vector<Point> points;
    rep(i, 0, N){
        int x, y;
        cin >> x >> y;
        points.push_back(Point(x, y));
    }


    if (K == 1) {cout << "Infinity" << endl; return 0;}

    vector<vector<int>> used(310, vector<int>(310, 0));
    vector<int> cnt(310, 0);
    rep(i, 0, N-1){
        rep(j, i+1, N){
            if (used[i][j]) continue;

            Point a = points[i];
            Point b = points[j];
            
            int cur = 2;
            vector<int> onLines = {i, j};
            rep(k, j+1, N){
                if (used[j][k] or used[i][k]) continue;

                Point c = points[k];
                if (isPointOnLine(a, b, c)){
                    cur++;
                    onLines.push_back(k);
                }
            }

            rep(l, 0, onLines.size()-1){
                rep(r, l+1, onLines.size()){
                    int a = onLines[l];
                    int b = onLines[r];
                    used[a][b] = used[b][a] = 1;
                }
            }

            cnt[cur]++;
        }
    }

    ll res = 0;
    rep(i, K, 310){
        res += cnt[i];
    }
    cout << res << endl;
}