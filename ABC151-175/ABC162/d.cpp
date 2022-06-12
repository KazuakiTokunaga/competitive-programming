#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)

int main() {
    int n; string s;
    cin >> n >> s;
    
    vector<int> rs, gs, bs;
    int r=0, g=0, b=0;
    rep(i, 0, n){
        if (s[i] == 'R') r++;
        if (s[i] == 'G') g++;
        if (s[i] == 'B') b++;
        rs.push_back(r);
        gs.push_back(g);
        bs.push_back(b);
    }

    // for (auto i: rs) {cout << i << ' ';} cout << endl;
    // for (auto i: gs) {cout << i << ' ';} cout << endl;
    // for (auto i: bs) {cout << i << ' ';} cout << endl;
    

    ll res = 0;
    rep(i, 0, n-2){
        int count_g = gs[n-1] - gs[i];
        int count_r = rs[n-1] - rs[i];
        int count_b = bs[n-1] - bs[i];
        if (s[i] == 'R'){
            // cout << count_g << " " << count_b << endl;
            res += count_g * count_b;
            rep(j, 1, n){
                int k = 2 * j;
                if (k >= n) break;
                if (s[i+j] == 'G' and s[i+k] == 'B') res--;
                if (s[i+j] == 'B' and s[i+k] == 'G') res--;
            }
        }
        if (s[i] == 'G'){
            res += count_r * count_b;
            rep(j, 1, n){
                int k = 2 * j;
                if (k >= n) break;
                if (s[i+j] == 'B' and s[i+k] == 'R') res--;
                if (s[i+j] == 'R' and s[i+k] == 'B') res--;
            }
        }
        if (s[i] == 'B'){
            res += count_g * count_r;
            rep(j, 1, n){
                int k = 2 * j;
                if (k >= n) break;
                if (s[i+j] == 'R' and s[i+k] == 'G') res--;
                if (s[i+j] == 'G' and s[i+k] == 'R') res--;
            }
        }
    }

    cout << res << endl;

}