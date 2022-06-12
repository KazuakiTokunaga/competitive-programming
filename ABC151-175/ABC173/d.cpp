#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
using P = pair<int, int>;

int main() {
    int n;
    cin >> n;
    
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    
    int t1 = a.back(); a.pop_back(); 
    int t2 = a.back(); a.pop_back();
    ll res = t1;

    auto c = [](P l, P r) { return min(l.first, l.second) <= min(r.first, r.second); };
    priority_queue<P, vector<P>, decltype(c)> q(c);

    q.push(make_pair(t1, t2));
    q.push(make_pair(t1, t2));
    while (!a.empty()){
        auto p = q.top(); q.pop();
        res += min(p.first, p.second);

        int t = a.back(); a.pop_back();
        q.push(make_pair(p.first, t));
        q.push(make_pair(p.second, t));
    }

    cout << res << endl;
}