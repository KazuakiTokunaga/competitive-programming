#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int l,r;
    cin >> l >> r;
    
    if (r-l >= 674) {
        cout << 0 << endl;
    } else {
        ll res = 2020;
        for (ll i = l; i < r; i++) {
            for (ll j = i+1; j < r+1; j++) {
                res = min(res, (i*j) % 2019);
            }
        }
        cout << res << endl;
    }
}