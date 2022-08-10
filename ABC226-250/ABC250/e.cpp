#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define all(x) (x).begin(),(x).end()

// https://atcoder.jp/contests/abc250/editorial/3906
int main() {
    int N;
    cin >> N;
    
    vector<int> A(N, 0);
    rep(i, 1, N+1) cin >> A[i];
    
    vector<int> B(N, 0);
    rep(i, 1, N+1) cin >> B[i];

    vector<int> Asize(N+1, 0);
    vector<int> Bsize(N+1, 0);
    set<int> Aset, Bset;
    vector<int> Avec, Bvec;

    rep(i, 1, N+1){
        if (!Aset.count(A[i])){
            Asize[i] = Asize[i-1] + 1;
            Aset.insert(A[i]);
            Avec.push_back(A[i]);

        } else {
            Asize[i] = Asize[i-1];
        }

        if (!Bset.count(B[i])){
            Bsize[i] = Bsize[i-1] + 1;
            Bset.insert(B[i]);
            Bvec.push_back(B[i]);

        } else {
            Bsize[i] = Bsize[i-1];
        }
    }

    vector<int> ok(N+1, 0);
    set<int> C;
    int min_size = min(Avec.size(), Bvec.size());
    rep(i, 0, min_size){
        if (C.count(Avec[i])) C.erase(Avec[i]);
        else C.insert(Avec[i]);

        if (C.count(Bvec[i])) C.erase(Bvec[i]);
        else C.insert(Bvec[i]);

        if (C.empty()) ok[i+1] = 1;
    }

    int Q;
    cin >> Q;
    rep(i, 0, Q){
        int x, y;
        cin >> x >> y;

        int s = Asize[x];
        string judge = "No";

        if (Asize[x] == Bsize[y]) if (ok[s]) judge = "Yes";
        cout << judge << endl;
    }
}