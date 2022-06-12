#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,k;
    cin >> n >> k;

    vector<int> h(n);
    for (int i = 0; i < n; i++) cin >> h[i];
    
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += h[i] >= k;
    }

    cout << ans << endl;
}