#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)

int main() {
    int r, d, x;
    cin >> r >> d >> x;
    
    for (int i = 0; i < 10; i++) {
        x = x * r - d;
        cout << x << endl;
    }
}