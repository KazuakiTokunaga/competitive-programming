#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> l(m);
    rep(i, 0, m){
        int k;
        cin >> k;

        rep(j, 0, k){
            int s;
            cin >> s;
            l[i].push_back(s);
        }
    }

    vector<int> p(m);
    for (int i = 0; i < m; i++) cin >> p[i];

    int res = 0;
    rep(i, 0, 1 << n){
        bool flag = true;
        rep(j, 0, m){
            int count = 0;
            for (int s: l[j]) {
                if (i & (1 << (s-1))){
                    count += 1;
                }
            }
            if(count % 2 != p[j]) flag = false;
        }
        if (flag) res += 1;
    }

    cout << res << endl;
}