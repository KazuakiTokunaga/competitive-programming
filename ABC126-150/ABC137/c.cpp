#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int n;
    cin >> n;
    
    map<string, ll> m;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        sort(s.begin(), s.end());
        m[s]++;
    }

    ll res = 0;
    for (auto i: m) {
        res += i.second * (i.second - 1) / 2;
    }

    cout << res << endl;

    
}