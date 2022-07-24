#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define all(x) (x).begin(),(x).end()

int main() {
    int N, M, X, T, D;
    cin >> N >> M >> X >> T >> D;
    
    if (N >= X){
        if (M >= X) cout << T << endl;
        else cout << T - (X - M) * D << endl;
    } else {
        if (M <= X) cout << T + (M - N) * D << endl;
        else cout << T + (X - N) * D << endl;
    }
}