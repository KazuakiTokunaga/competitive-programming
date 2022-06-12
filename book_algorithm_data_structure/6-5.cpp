//二分探索（広義）

#include <bits/stdc++.h>
using namespace std;
#define ll long long
constexpr int INF = 1000000000 + 8;

int main() {
    int n;
    cin >> n;
    
    vector<ll> h(n), s(n);
    for (int i = 0; i < n; i++) cin >> h[i] >> s[i];


    ll left = 0, right = INF;

    while (right - left > 1) {
        ll mid = (left + right) / 2;

        bool ok = true;
        vector<ll> t(n, 0);

        for (int i = 0; i < n; i++) {
            if (mid<h[i]) ok = false;
            else t[i] = (mid - h[i]) / s[i];
        }
        
        sort(t.begin(), t.end());
        for (int i = 0; i < n; i++) {
            if (t[i] < i) ok = false;
        }

        if (ok) right = mid;
        else left = mid;    
    }

    cout << right << endl;
}