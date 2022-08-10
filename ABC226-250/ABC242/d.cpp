#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define all(x) (x).begin(),(x).end()

int main() {
    string S;
    cin >> S;

    int Q;
    cin >> Q;

    rep(i, 0, Q){
        ll t, k;
        cin >> t >> k; k--;

        ll target;
        if (pow(2, t) > 1e18) target = 0;
        else {target = k / (ll)pow(2, t); k -= target * (ll)pow(2, t);}

        ll c = int(S[target]-'A'); // スタートの文字
        ll cnt = 0;
        while (k > 0){
            if (k % 2 == 1) c += 2;
            else c += 1;

            k /= 2;
            cnt++;
        }
        c += (t - cnt); // 残りの回数をゼロとして加算
        c %= 3;

        cout << char(c + 'A') << endl;
    }
}