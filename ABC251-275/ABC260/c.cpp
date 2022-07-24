#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define all(x) (x).begin(),(x).end()

int main() {
    ll N, X, Y;
    cin >> N >> X >> Y;
    
    ll A = 1, B = 0;
    while (N > 1){
        // レベルnの赤を変換
        B += X * A;
        
        // レベルnの青を変換
        A += B;
        B = B * Y;

        N--;
    }
    cout << B << endl;
}