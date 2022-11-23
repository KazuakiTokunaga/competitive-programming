#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define all(x) (x).begin(),(x).end()
const ll MOD = 998244353;

// https://atcoder.jp/contests/abc242/editorial/3516
int main() {
    int T;
    cin >> T;
    
    rep(_, 0, T){
        int n; string s;
        cin >> n >> s;

        // 確実にSより前に来るものをカウントする
        ll cnt = 0;
        int r = (n+1) / 2;
        rep(i, 0, r){
            ll c = int(s[i]-'A');
            cnt = (cnt * 26) % MOD + c;
        }

        // 先頭からSと同じであるような1通りについて、カウントされるかチェックする
        bool flg = true;
        rrep(i, r-1, 0){
            ll c = int(s[i]-'A');
            ll cr = int(s[n-1 - i] - 'A');
            if (c < cr) break;
            if (c > cr) {flg = false; break;}
        }

        if (flg) cnt++;
        cnt %= MOD;

        cout << cnt << endl;
    }
}