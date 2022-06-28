#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<ll, ll>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define all(x) (x).begin(),(x).end()
using Point = complex<ll>;

int main() {
    int N;
    cin >> N;

    vector<Point> Points;
    rep(i, 0, N){
        ll x, y;
        cin >> x >> y;
        Points.push_back({x, y});
    }

    int M;
    cin >> M;
    vector<int> XY(M+1, 0); // 0のときはそのまま、1のときはXとYが入れ替わる
    vector<int> XSign(M+1, 1); // Xにかかる符号
    vector<int> YSign(M+1, 1); // Yにかかる富豪
    vector<ll> XAdd(M+1, 0); // Xに加えられる数値
    vector<ll> YAdd(M+1, 0); // Yに加えられる数値
    rep(i, 1, M+1){
        int op;
        cin >> op;
        if (op == 1) {
            if (XY[i-1]){
                XY[i] = 1 - XY[i-1];
                YSign[i] = YSign[i-1] * (-1);
                XSign[i] = XSign[i-1];
                YAdd[i] = YAdd[i-1] * (-1);
                XAdd[i] = XAdd[i-1];
            } else {
                XY[i] = 1 - XY[i-1];
                XSign[i] = XSign[i-1] * (-1);
                YSign[i] = YSign[i-1];
                XAdd[i] = XAdd[i-1] * (-1);
                YAdd[i] = YAdd[i-1];
            }
        }
        if (op == 2) {
            if (XY[i-1]){
                XY[i] = 1 - XY[i-1];
                XSign[i] = XSign[i-1] * (-1);
                YSign[i] = YSign[i-1];
                XAdd[i] = XAdd[i-1] * (-1);
                YAdd[i] = YAdd[i-1];
            } else {
                XY[i] = 1 - XY[i-1];
                YSign[i] = YSign[i-1] * (-1);
                XSign[i] = XSign[i-1];
                YAdd[i] = YAdd[i-1] * (-1);
                XAdd[i] = XAdd[i-1];
            }
        }
        if (op == 3){
            ll p; cin >> p;
            if (XY[i-1]){
                XY[i] = XY[i-1];
                XSign[i] = XSign[i-1];
                YSign[i] = YSign[i-1] * (-1);
                YAdd[i] = 2*p - YAdd[i-1];
                XAdd[i] = XAdd[i-1];
            } else {
                XY[i] = XY[i-1];
                YSign[i] = YSign[i-1];
                XSign[i] = XSign[i-1] * (-1);
                XAdd[i] = 2*p - XAdd[i-1];
                YAdd[i] = YAdd[i-1];
            }
        }
        if (op == 4){
            ll p; cin >> p;
            if (XY[i-1]){
                XY[i] = XY[i-1];
                YSign[i] = YSign[i-1];
                XSign[i] = XSign[i-1] * (-1);
                XAdd[i] = 2*p - XAdd[i-1];
                YAdd[i] = YAdd[i-1];
            } else {
                XY[i] = XY[i-1];
                XSign[i] = XSign[i-1];
                YSign[i] = YSign[i-1] * (-1);
                YAdd[i] = 2*p - YAdd[i-1];
                XAdd[i] = XAdd[i-1];
            }
        }
    }

    int Q;
    cin >> Q;
    rep(i, 0, Q){
        int a, b;
        cin >> a >> b;
        Point p = Points[b-1];
        ll x = p.real(), y = p.imag();

        x = (x * XSign[a]) + XAdd[a];
        y = (y * YSign[a]) + YAdd[a];
        
        if (XY[a]) cout << y << " " << x << endl;
        else cout << x << " " << y << endl;
    }
}