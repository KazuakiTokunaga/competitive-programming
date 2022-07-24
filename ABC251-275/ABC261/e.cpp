#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define all(x) (x).begin(),(x).end()

int main() {
    int N;
    ll C;
    cin >> N >> C;
    
    vector<vector<ll>> memo(31, vector<ll>(2, 0));
    rep(i, 0, 31){
        memo[i][1] = 1;
    }

    ll X = C;
    rep(i, 0, N){
        int t;
        ll a;
        cin >> t >> a;
        rep(j, 0, 31){
            int a1 = (a >> j) & 1;
            
            if (t == 1){
                memo[j][1] = a1 & memo[j][1];
                memo[j][0] = a1 & memo[j][0];
            } else if (t == 2){
                memo[j][1] = a1 | memo[j][1];
                memo[j][0] = a1 | memo[j][0];    
            } else {
                memo[j][1] = a1 ^ memo[j][1];
                memo[j][0] = a1 ^ memo[j][0];
            }
        }

        ll nxt = 0;
        rep(j, 0, 31){
            nxt += pow(2, j) * memo[j][(X >> j) & 1];
        }
        cout << nxt << endl;
        X = nxt;
    }
}