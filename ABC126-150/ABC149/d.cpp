#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)

int main() {
    int n, k, r, s, p; string t;
    cin >> n >> k >> r >> s >> p >> t;

    string hands = "";
    int res = 0;
    rep(i, 0, n){
        if (t[i] == 'p'){
            if (i < k or hands[i-k] != 's'){
                hands += 's';
                res += s;
            } else if (i+k < n and t[i+k] != 'r'){
                hands += 'p';
            } else {
                hands += 'r';
            }
        } else if (t[i] == 's'){
            if (i < k or hands[i-k] != 'r'){
                hands += 'r';
                res += r;
            } else if (i+k < n and t[i+k] != 'p'){
                hands += 's';
            } else {
                hands += 'p';
            }
        } else {
            if (i < k or hands[i-k] != 'p'){
                hands += 'p';
                res += p;
            } else if (i+k < n and t[i+k] != 's'){
                hands += 'r';
            } else {
                hands += 's';
            }
        }
    }

    cout << res << endl;
}