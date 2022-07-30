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
    
    // A[i]: iの場所
    // B[i]: i番目にある数
    vector<int> A(N+1, 0);
    vector<int> B(N+1, 0);
    rep(i, 1, N+1) {A[i] = i; B[i] = i;}

    rep(i, 0, Q){
        int x;
        cin >> x;

        int p = A[x];
        int nxt = p+1;
        if (p == N) nxt = p-1;
        int r = B[nxt];

        A[x] = nxt;
        A[r] = p;
        B[p] = r;
        B[nxt] = x;
    }
    
    rep(i, 1, N+1){
        cout << B[i] << " ";
    }
    cout << endl;


}