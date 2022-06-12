#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int n;
    cin >> n;

    vector<int> p(n);
    for (int i = 0; i < n; i++) cin >> p[i];

    vector<int> q(n);
    copy(p.begin(), p.end(), q.begin());
    sort(q.begin(), q.end());

    int res = 0;
    for (int i = 0; i < n; i++) {
        if (p[i] != q[i]){
            res += 1;
        }
    }

    cout << (res <= 2 ? "YES" : "NO") << endl;
    
}