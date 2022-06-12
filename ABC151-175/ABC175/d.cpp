#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> p(n);
    for (int i = 0; i < n; i++) cin >> p[i];
    
    vector<int> c(n);
    for (int i = 0; i < n; i++) cin >> c[i];
    
    ll res = -1 * (1LL << 60);
    rep(i, 0, n){
        int v = p[i];
        int cycle_count = 1;
        ll cycle_point = c[v-1];
        while (i != v-1){
            v = p[v-1];
            cycle_point += c[v-1];
            cycle_count++;
        }

        // cout << i << " " << cycle_count << " " << cycle_point << endl;

        ll point = 0;
        ll move_count = 1;
        int v1 = v;
        while (move_count <= k){
            v1 = p[v1-1];
            point += c[v1-1];
            ll add = max((ll)0, ((k-move_count) / cycle_count) * cycle_point);
            res = max(res, point + add);
            if (i == v1-1) break;
            move_count++;
        }
    }

    cout << res << endl;
}