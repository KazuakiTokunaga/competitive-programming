#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)

int main() {
    int n, q; string s;
    cin >> n >> s >> q;
    
    int rev = 0;
    rep(i, 0, q){
        int t, a, b;
        cin >> t >> a >> b;

        if (t == 2) rev = 1 - rev;
        if (t == 1){
            if (rev){
                if (a > n) a = (a-n);
                else a += n;
                if (b > n) b = (b-n);
                else b += n;
                swap(s[a-1], s[b-1]);
            } else {
                swap(s[a-1], s[b-1]);
            }
        }
    }

    if (rev) cout << s.substr(n) + s.substr(0, n) << endl;
    else cout << s << endl;
}