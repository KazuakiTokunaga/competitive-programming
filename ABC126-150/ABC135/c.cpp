#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int n;
    cin >> n;

    vector<int> a(n+1);
    for (int i = 0; i < n+1; i++) cin >> a[i];

    vector<int> b(n);
    for (int i = 0; i < n; i++) cin >> b[i];
    

    int before = 0;
    ll res = 0;
    for (int i = 0; i < n+1; i++) {
        if (a[i] <= before) {
            res += a[i];
            a[i] = 0;
        } else {
            res += before;
            a[i] = a[i] - before;
        }

        if (a[i] <= b[i]) {
            res += a[i];
            before = b[i] - a[i];
        } else {
            res += b[i];
            before = 0;
        }
    }

    cout << res << endl;
}