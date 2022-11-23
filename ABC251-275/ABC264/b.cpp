#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define all(x) (x).begin(),(x).end()

int main() {
    int R, C;
    cin >> R >> C; R--; C--;
    
    int r = min(R, 14-R);
    int c = min(C, 14-C);
    if (min(r, c) % 2) cout << "white" << endl;
    else cout << "black" << endl;
}