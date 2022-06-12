#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n), b(n), c(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    for (int i = 0; i < n-1; i++) cin >> c[i];
    
    int ans = 0, before = -2;
    for (int i: a) {
        ans += b[i-1];
        if (i == before + 1){
            ans += c[before-1];
        }
        before = i;
    }
    
    cout << ans << endl;

}