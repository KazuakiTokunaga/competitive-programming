#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)

int main() {
    int n, k;
    cin >> n >> k;
    
    vector<int> p(n);
    for (int i = 0; i < n; i++) cin >> p[i];

    vector<long double> es;
    rep(i, 0, n){
        int dice = p[i];
        long double e = 0;
        rep(j, 1, dice+1){
            e += ((long double)1 / dice) * j;
        }
        es.push_back(e);
    }

    int i = 0, j = k-1;
    long double res = 0;
    long double s = 0;
    rep(i, 0, k){
        s += es[i];
    }

    while (true){
        res = max(res, s);
        j++;
        if (j >= n)  break;
        s += es[j];
        s -= es[i];
        i++;
    }

    cout << fixed << setprecision(15);
    cout << res << endl;

}