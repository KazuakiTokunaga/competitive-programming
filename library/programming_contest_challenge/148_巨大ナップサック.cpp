// 半分全列挙
// W, Vが巨大でDPが使えないが、品物の数(N)が少ないときのナップサック問題
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<ll, ll>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define all(x) (x).begin(),(x).end()

int main() {
    int n; ll W;
    cin >> n >> W;

    vector<ll> w(n, 0), v(n, 0);
    rep(i, 0, n) cin >> w[i] >> v[i];
    
    int n2 = n / 2;
    vector<pii> ps(n2);
    rep(i, 0, 1 << n2){
        ll sw = 0, sv = 0;
        for (int j = 0; j < n2; j++) {
            if (i & 1 << j == 1) {
                sw += w[j];
                sv += v[j];
            }
        }
        ps[i] = make_pair(sw, sv);
    }

    sort(all(ps));
    vector<pii> ps1; 
    ps1.push_back(ps[0]);
    rep(i, 1, n2){
        if (ps1.back().second < ps[i].second){
            ps1.push_back(ps[i]);
        }
    }

    ll res = 0;
    rep(i, 0, 1 << (n-n2)){
        ll sw = 0, sv = 0;
        rep(j, 0, n-n2){
            if (i & 1 << j == 1){
                sw += w[n2+j];
                sv += v[n2+j];
            }
        }
        if (sw <= W){
            pii p = {W-sw, 1LL << 60};
            auto iter = lower_bound(ps1.begin(), ps1.end(), p) - 1; // lower_boundで取得できる要素の1つ前
            ll tv = (*iter).second;
            res = max(res, sv + tv);
        }
    }

    cout << res << endl;
}

/*
4 5
2 3
1 2
3 4
2 4
*/