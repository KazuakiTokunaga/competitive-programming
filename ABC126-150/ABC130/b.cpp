#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int n,x;
    cin >> n >> x;

    vector<int> l(n);
    for (int i = 0; i < n; i++) cin >> l[i];
    
    int res = 1;
    int d = 0;
    for (int i = 0; i < n; i++) {
        d += l[i];
        if (d <= x) {
            res += 1;
        }
    }

    cout << res << endl;
}