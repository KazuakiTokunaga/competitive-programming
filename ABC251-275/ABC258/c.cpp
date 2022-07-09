#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define all(x) (x).begin(),(x).end()

int main() {
    int N, Q;
    cin >> N >> Q;

    string S;
    cin >> S;

    int cnt = 0;
    rep(i, 0, Q){
        int t, x;
        cin >> t >> x;

        
        if (t == 1){
            cnt += x;
            cnt %= N;
        } else {
            x = x - cnt - 1;
            x %= N;
            while (x < 0) x += N;

            cout << S[x] << endl;
        }
    }
}