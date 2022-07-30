#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define all(x) (x).begin(),(x).end()

int main() {
    int N, W;
    cin >> N >> W;
    
    vector<int> A(N);
    rep(i, 0, N) cin >> A[i];
    
    set<int> goods;
    rep(i, 0, N){
        if (A[i] <= W) goods.insert(A[i]);
    }
    rep(i, 0, N-1){
        rep(j, i+1, N){
            int n = A[i] + A[j];
            if (n <= W) goods.insert(n);
        }
    }

    rep(i, 0, N-2){
        rep(j, i+1, N-1){
            rep(k, j+1, N){
                int n = A[i] + A[j] + A[k];
                if (n <= W) goods.insert(n);
            }
        }
    }

    cout << goods.size() << endl;
}