#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> b(n-1);
    for (int i = 0; i < n-1; i++) cin >> b[i];

    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            ans += b[i];
        } else if (i == n-1) {
            ans += b[i-1];
        } else {
            ans += min(b[i], b[i-1]);
        }
    }
    
    cout << ans << endl;
}