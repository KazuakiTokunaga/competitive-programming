#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define all(x) (x).begin(),(x).end()

using D = long double;
using Point = complex<D>;
const D EPS = 1e-7;
bool equal(const D &a, const D &b) { return fabs(a - b) < EPS; }

struct Circle {
    Point p;
    D r;

    Circle() = default;
    Circle(Point p, D r) : p(p), r(r) {}
};

int main() {
    int N;
    cin >> N;

    D sx, sy, tx, ty;
    cin >> sx >> sy >> tx >> ty;
    Point s = {sx, sy}, t = {tx, ty};

    vector<Circle> C;
    rep(i, 0, N){
        D x, y, r;
        cin >> x >> y >> r;
        C.push_back(Circle({x, y}, r));
    }

    vector<vector<int>> graph(N);
    int S = -1, T = -1;

    // 他の円との距離を調べて、辺を張る
    rep(i, 0, N-1){
        rep(j, i+1, N){
            D dist = abs(C[i].p - C[j].p);
            if (dist >= abs(C[i].r - C[j].r) and dist <= C[i].r + C[j].r){
                graph[i].push_back(j);
                graph[j].push_back(i);
            }
        }
    }

    // スタートとゴールの円を調べる
    rep(i, 0, N){
        if (equal(C[i].r, abs(C[i].p - s))) S = i;
        if (equal(C[i].r, abs(C[i].p - t))) T = i;
    }


    vector<int> used(N, 0);
    queue<int> q;
    q.push(S);
    bool res = false;
    while (!q.empty()){
        int c = q.front(); q.pop();
        used[c] = 1;
        if (c == T) {res = true; break;}

        for (int nxt: graph[c]) {
            if (used[nxt]) continue;
            else q.push(nxt);
        }
    }

    if (res) cout << "Yes" << endl;
    else cout << "No" << endl;
}