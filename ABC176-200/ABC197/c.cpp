#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)

int n;
vector<int> a;
vector<int> part;
ll res = 1LL << 60;

bool dfs(int i) {
    if (i == n) {
        ll ans = part[0];
        rep(j, 0, part.size()){
            if (j==0) continue;
            ans = (ans ^ part[j]);
        }

        // cout << res << " " << ans << " part: ";
        // for (auto i: part) {cout << i << ' ';} cout << endl;
        
        res = min(res, ans);
        return true;
    }

    int last = part.back(); part.pop_back();
    part.push_back(last | a[i]);
    dfs(i+1);
    part.pop_back();
    part.push_back(last);

    part.push_back(a[i]);
    dfs(i+1);
    part.pop_back();

    return true;
}

int main() {
    cin >> n;

    rep(i, 0, n) {
        int t;
        cin >> t;
        a.push_back(t);
    }
    
    part.push_back(a[0]);
    dfs(1);
    cout << res << endl;
}