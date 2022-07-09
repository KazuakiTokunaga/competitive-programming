#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define all(x) (x).begin(),(x).end()

int main() {
    int N, X;
    cin >> N >> X;

    vector<vector<int>> stages;
    rep(i, 0, N){
        int a, b;
        cin >> a >> b;
        
        vector<int> stage = {a,b,a+b};
        stages.push_back(stage);
    }

    ll res = 2LL << 60;
    ll accum = 0;
    rep(i, 0, N){
        if (i > X) break;
        vector<int> stage = stages[i];
        accum += stage[2];
        ll t =  accum + (ll)(X - i - 1) * stage[1];
        res = min(res, t);
    }
    
    cout << res << endl;
}