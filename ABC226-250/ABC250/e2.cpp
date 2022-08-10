#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define all(x) (x).begin(),(x).end()

// https://atcoder.jp/contests/abc250/editorial/3948
int main() {
    int N;
    cin >> N;
    
    vector<int> A(N);
    rep(i, 0, N) cin >> A[i];
    
    vector<int> B(N);
    rep(i, 0, N) cin >> B[i];
    
    int idx = 0;
    map<int, int> fmap;
    vector<int> Avec;

    rep(i, 0, N){
        if (!fmap.count(A[i])){
            idx++;
            Avec.push_back(idx);
            fmap[A[i]] = idx;
        } else {
            Avec.push_back(idx);
        }
    }

    vector<pii> Bvec;
    int bcur = 0;
    set<int> Bset;
    rep(i, 0, N){
        if (fmap.count(B[i])){
            Bset.insert(fmap[B[i]]);
            bcur = max(bcur, fmap[B[i]]);
            Bvec.push_back({Bset.size(), bcur});
        } else {
            idx++;
            fmap[B[i]] = idx;
            Bset.insert(fmap[B[i]]);
            bcur = max(bcur, fmap[B[i]]);
            Bvec.push_back({Bset.size(), bcur});
        }
    }
    
    int Q;
    cin >> Q;
    rep(i, 0, Q){
        int x, y; 
        cin >> x >> y; x--; y--;
        if (Avec[x] == Bvec[y].first and Avec[x] == Bvec[y].second) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}