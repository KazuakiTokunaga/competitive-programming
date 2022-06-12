#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int n;
    cin >> n;
    
    ll cur = 0;
    for (int i = 0; i < n; i++) {
        ll a;
        cin >> a;

        if (cur > a){
            cout << "No" << endl;
            return 0;
        } else {
            cur = max(a-1, cur);
        }
    }

    cout << "Yes" << endl;
    return 0;
}