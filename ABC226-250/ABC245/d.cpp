#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define all(x) (x).begin(),(x).end()

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> A(N+1);
    rep(i, 0, N+1) cin >> A[i];
    
    vector<int> C(N+M+1);
    rep(i, 0, N+M+1) cin >> C[i];
    
    
    vector<int> B(M+1, 0);
    vector<int> AB(N+M+1, 0);
    rrep(i, M, 0){
        int a = A[N];
        int b = (C[N+i] - AB[N+i]) / a;

        B[i] = b;        
        rep(j, 0, N+1){
            AB[i+j] += b * A[j]; // Bのi次はbであることを踏まえて、i+j次の係数を加える
        }
    }
    
    for (auto i: B) {cout << i << ' ';} cout << endl;
}