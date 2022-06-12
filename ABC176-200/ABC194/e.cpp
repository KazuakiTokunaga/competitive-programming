#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
const int INF = pow(10, 7);

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    rep(i, 0, n) cin >> a[i];
    
    vector<int> cnt(n+1);
    rep(i, 0, m){
        cnt[a[i]]++;
    }

    // for (auto i: cnt) {cout << i << ' ';} cout << endl;
    
    priority_queue<int, vector<int>, greater<int>> q;
    rep(i, 0, n+10){
        if (cnt[i] == 0){
            q.push(i);
        }
    }

    // cout << q.top() << endl;

    int res = q.top();
    rep(i, m, n){
        cnt[a[i]]++;
        cnt[a[i-m]]--;
        
        if (cnt[a[i-m]] == 0) q.push(a[i-m]);
        int r = q.top();
        while (cnt[r] != 0){
            q.pop();
            r = q.top();
        }
        res = min(res, q.top());
    }

    cout << res << endl;
}