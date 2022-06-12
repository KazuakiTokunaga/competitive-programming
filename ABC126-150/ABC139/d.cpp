#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ll n;
    cin >> n;
    
    ll res = 0;
    for (ll i = 1; i < n; i++) {
        res += i;
    }

    cout << res << endl;
}