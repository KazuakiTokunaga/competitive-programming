#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define all(x) (x).begin(),(x).end()

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    
    if (a <= b and b <= c) cout << "Yes" << endl;
    else if (a >= b and b >= c) cout << "Yes" << endl;
    else cout << "No" << endl;
}