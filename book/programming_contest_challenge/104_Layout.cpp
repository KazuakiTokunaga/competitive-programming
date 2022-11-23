// 差分制約問題を最短路問題とみなす
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define all(x) (x).begin(),(x).end()
const int INF = pow(10, 9) + 7;

int n, ml, md;
vector<int> d;
vector<int> als, bls, dls;
vector<int> ads, bds, dds;
bool updated = false;

void update(int &x, int y){
    if (x > y){
        x = y;
        updated = true;
    }
}

void bellmanford(){
    rep(k, 0, n){
        updated = false;
        rep(i, 0, n-1){
            if (d[i+1] < INF) update(d[i], d[i+1]);
        }
        rep(i, 0, ml){
            if (d[als[i]-1] < INF) update(d[bls[i]-1], d[als[i]-1] + dls[i]);
        }
        rep(i, 0, md){
            if (d[bds[i]-1] < INF) update(d[ads[i]-1], d[bds[i]-1] - dds[i]);
        }
    }
}

int main() {
    cin >> n >> ml >> md;

    als.assign(ml, 0);
    bls.assign(ml, 0);
    dls.assign(ml, 0);
    ads.assign(md, 0);
    bds.assign(md, 0);
    dds.assign(md, 0);

    rep(i, 0, ml){
        cin >> als[i] >> bls[i] >> dls[i];
    }
    rep(i, 0, md){
        cin >> ads[i] >> bds[i] >> dds[i];
    }

    d.assign(n, 0);
    bellmanford();
    if (updated) {
        cout << -1 << endl;
        return 0;
    }

    d.assign(n, INF);
    d[0] = 0;
    bellmanford();
    for (auto i: d) {cout << i << ' ';} cout << endl;
    
    int res = d[n-1];
    if (res == INF) res = -2;
    cout << res << endl;
}

/*
4 2 1
1 3 10
2 4 20
2 3 3
*/