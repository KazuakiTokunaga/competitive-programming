#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int n;
    cin >> n;

    vector<int> p(n);
    for (int i = 0; i < n; i++) cin >> p[i];
    
    int res = 0;
    for (int i = 1; i < n-1; i++) {
        vector<int> q = {p[i-1], p[i], p[i+1]};
        sort(q.begin(), q.end());

        if (p[i] == q[1]) {
            res += 1;
        }
    }
    
    cout << res << endl;
}