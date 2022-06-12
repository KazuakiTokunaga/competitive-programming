#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)

int main() {
    ll x, y, a, b;
    cin >> x >> y >> a >> b;

    ll exp = 0;
    while (y > x * a and x < (x + b) / a) {
        x *= a;
        exp++;
    }
    if (y > x){
        if ((y-x) % b == 0) exp += (y-x) / b - 1;
        else exp += (y - x) / b;
    }
    cout << exp << endl;
}