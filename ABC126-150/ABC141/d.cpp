#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int n, m;
    cin >> n >> m;
    
    priority_queue<ll, vector<ll>, less<ll>> q;
    for (int i = 0; i < n; i++) {
        ll a;
        cin >> a;
        q.push(a);
    }

    for (int i = 0; i < m; i++) {
        ll c = q.top();
        q.pop();
        q.push(c/2);
    }

    ll res = 0;
    for (int i = 0; i < n; i++) {
        res += q.top(); 
        q.pop();
    }
    cout << res << endl;
}