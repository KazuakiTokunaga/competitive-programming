#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define all(x) (x).begin(),(x).end()

// 考え方はここが参考になりそう
// https://kyo-pro.hatenablog.com/entry/ari-hon-2-7

int main() {
    int m, x; double p;
    cin >> m >> p >> x;
    int n = 1 << m;

    vector<double> dp1((1<<m)+1, 0);
    vector<double> dp2((1<<m)+1, 0);
    dp1[n] = 1.0;

    rep(r, 0, m){
        rep(i, 0, n+1){
            int jub = min(i, n-i);
            double t = 0.0;
            rep(j, 0, jub+1){
                t = max(t, p * dp1[i+j] + (1-p) * dp1[i-j]);
            }
            dp2[i] = t;
        }
        swap(dp1, dp2);
    }

    int i = (ll)x * n / 1000000;
    cout << dp1[i] << endl;
}

/*
3 0.75 600000
*/