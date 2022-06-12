#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)

int main() {
    ll a,b,x;
    cin >> a >> b >> x;

    ll base = 1;
    while (true){
        int size = to_string(base).size();
        ll value = size * b + base * a;
        if (value > x) break;
        else base *= 10;
    }

    base /= 10;
    ll value = to_string(base).size() * b + base * a;

    ll res = 0;
    res =  base + (x - value) / a;

    cout << max((ll)min(min(res, base*10-1), (ll)pow(10,9)), (ll)0) << endl;
}