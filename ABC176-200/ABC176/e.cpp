#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define all(x) (x).begin(),(x).end()
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false;}
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return true; } return false;}

int main() {
    int H, W, M;
    cin >> H >> W >> M;

    map<pii, int> Ms;
    vector<int> Hs(H+1, 0);
    vector<int> Ws(W+1, 0);

    rep(i, 0, M){
        int h, w;
        cin >> h >> w;
        Hs[h]++; Ws[w]++;
        
        pii p = make_pair(h, w);
        Ms[p]++;
    }

    int h_max = -1;
    rep(i, 0, H+1) chmax(h_max, Hs[i]);

    int w_max = 0;
    rep(i, 0, W+1) chmax(w_max, Ws[i]);

    vector<int> h_idx;
    rep(i, 0, H+1) if (Hs[i] == h_max) h_idx.push_back(i);
    vector<int> w_idx;
    rep(i, 0, W+1) if (Ws[i] == w_max) w_idx.push_back(i);
    
    
    int res = h_max + w_max;
    for (int i: h_idx) {
        for (int j: w_idx) {
            if (!Ms.count({i, j})) {cout << res << endl; return 0;}
        }
    }
    res--;
    cout << res << endl;
}