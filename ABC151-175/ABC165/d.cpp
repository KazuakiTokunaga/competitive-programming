#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)

int main() {
    ll a, b, n;
    cin >> a >> b >> n;

    ll x = min(b-1, n);
    cout << (a * x) / b - a * (x / b) << endl;
}