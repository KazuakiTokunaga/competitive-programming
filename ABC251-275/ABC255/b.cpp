#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using D = long double;
using Point = complex<D>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define all(x) (x).begin(),(x).end()

int main() {
    int N, K;
    cin >> N >> K;
    
    vector<int> A(K);
    rep(i, 0, K) {cin >> A[i]; A[i]--;}

    vector<Point> P;
    rep(i, 0, N){
        D x, y;
        cin >> x >> y;

        Point p = {x, y};
        P.push_back(p);
    }

    D res = 0;
    rep(i, 0, N){
        Point p = P[i];

        D dist = pow(10, 9);
        rep(j, 0, K){
            Point t = P[A[j]];
            dist = min(dist, abs(p-t));
        }

        res = max(res, dist);
    }

	cout << fixed << setprecision(15);
    cout << res << endl;
}