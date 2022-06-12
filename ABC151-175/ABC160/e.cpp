#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)

int main() {
    int x, y, a, b, c;
    cin >> x >> y >> a >> b >> c;
    
    vector<int> p(a);
    for (int i = 0; i < a; i++) cin >> p[i];
    sort(p.begin(), p.end(), greater<>());

    priority_queue<int, vector<int>, greater<int>> pq;
    rep(i, 0, x) pq.push(p[i]);
    
    vector<int> q(b);
    for (int i = 0; i < b; i++) cin >> q[i];
    sort(q.begin(), q.end(), greater<int>());

    priority_queue<int, vector<int>, greater<int>> qq;
    rep(i, 0, y) qq.push(q[i]);


    vector<int> r(c);
    for (int i = 0; i < c; i++) cin >> r[i];
    sort(r.begin(), r.end());

    int pt = pq.top(), qt = qq.top();
    while (!r.empty() and (r.back() > pt or r.back() > qt)){
        if (pt < qt){
            pq.push(r.back());
            pq.pop();
            r.pop_back();
            pt = pq.top();
        } else {
            qq.push(r.back());
            qq.pop();
            r.pop_back();
            qt = qq.top();
        }
    }

    ll res = 0;
    while (!pq.empty()){
        res += pq.top(); pq.pop();
    }
    while (!qq.empty()){
        res += qq.top(); qq.pop();
    }
    cout << res << endl;
}