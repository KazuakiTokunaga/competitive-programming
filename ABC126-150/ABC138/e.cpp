#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define all(x) (x).begin(),(x).end()

int main() {
    string s, t;
    cin >> s >> t;

    int ssize = s.size();
    map<char, vector<int>> cnt;
    rep(i, 0, ssize){
        char c = s[i];
        cnt[c].push_back(i+1);
    }
    
    ll res = 0;
    int cur = 0;
    rep(i, 0, t.size()){
        char c = t[i];
        vector<int> idx = cnt[c];
        if (idx.size() == 0){ 
            cout << -1 << endl;
            return 0;
        }

        auto iter = upper_bound(all(idx), cur);
        if (iter == idx.end()){
            res += idx[0] - cur + ssize;
            cur = idx[0];
        } else {
            res += *iter - cur;
            cur = *iter;
        }
    }

    cout << res << endl;
}