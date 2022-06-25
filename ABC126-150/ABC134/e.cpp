#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define all(x) (x).begin(),(x).end()

int main() {
    int n;
    cin >> n;
    
    vector<int> a(n);
    rep(i, 0, n) cin >> a[i];
    
    vector<int> cur;
    cur.push_back(a[0]);
    int res = 1;

    vector<int> nxt;

    rep(i, 1, n){
        int p = a[i];
        if (cur.back() < p){
            auto iter = upper_bound(all(cur), p, greater<int>());
            *iter = p;
        } else {
            res++;
            cur.push_back(p);
        }
    }

    cout << res << endl;
}