#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define all(x) (x).begin(),(x).end()

int main() {
    ll X, A, D, N;
    cin >> X >> A >> D >> N;
    
    if (!D){
        cout << abs(X-A) << endl;
        return 0;
    }
    
    ll cnt = (X - A) / D;
    if (cnt < 0){
        cout << abs(X-A) << endl;
    } else if (cnt < N - 1){
        ll a = abs(X - (cnt * D + A));
        ll b = abs(X - ((cnt+1) * D + A));
        cout << min(a, b) << endl;
    } else {
        cout << abs(X - ((N-1)*D+A)) << endl;
    }
}