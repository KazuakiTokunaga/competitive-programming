#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define all(x) (x).begin(),(x).end()

ld getProb(int i){
    return ld(i) / 6;
}

int main() {
    int N;
    cin >> N;
    
    if (N == 1) {cout << 3.5 << endl; return 0;}
    if (N == 2) {cout << ld(153) / 36 << endl; return 0;}

    vector<ld> res(310, 3.5);
    rep(i, 2, 302){
        ld cur = res[i-1];
        if (cur < 4){
            res[i] = 6 * getProb(1) + 5 * getProb(1)+ 4 * getProb(1) + cur * getProb(3);
        } else if (cur < 5){
            res[i] = 6 * getProb(1) + 5 * getProb(1) + cur * getProb(4);
        } else {
            res[i] = 6 * getProb(1) + cur * getProb(5);
        }
    }
    
    cout << fixed << setprecision(15);
    cout << res[N] << endl;

}