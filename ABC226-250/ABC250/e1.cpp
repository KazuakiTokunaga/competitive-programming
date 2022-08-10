#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define all(x) (x).begin(),(x).end()
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false;}

// https://atcoder.jp/contests/abc250/editorial/4518
int main() {
    int N;
    cin >> N;
    
    vector<int> A(N);
    rep(i, 0, N) cin >> A[i];
    
    vector<int> B(N);
    rep(i, 0, N) cin >> B[i];
    
    map<int, int> Amap, Bmap;
    rep(i, 0, N){
        if (!Amap.count(A[i])) Amap[A[i]] = i;
        if (!Bmap.count(B[i])) Bmap[B[i]] = i;
    }

    vector<int> Avec, Bvec;
    int acur = 0, bcur = 0;
    rep(i, 0, N){
        if (Bmap.count(A[i])) chmax(acur, Bmap[A[i]]);
        else acur = N;
        Avec.push_back(acur);

        if (Amap.count(B[i])) chmax(bcur, Amap[B[i]]);
        else bcur = N;
        Bvec.push_back(bcur);
    }

    int Q;
    cin >> Q;
    rep(i, 0, Q){
        int x, y;
        cin >> x >> y; x--; y--;
        if (Avec[x] <= y and Bvec[y] <= x) cout << "Yes" << endl;
        else cout << "No" << endl;
    }

}