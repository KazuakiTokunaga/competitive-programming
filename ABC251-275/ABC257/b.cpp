#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define all(x) (x).begin(),(x).end()

int main() {
    int N, K, Q;
    cin >> N >> K >> Q;
    
    vector<int> A(K);
    rep(i, 0, K) cin >> A[i];
    
    rep(i, 0, Q){
        int l;
        cin >> l;

        if (A[l-1] == N or (l < N and A[l-1] + 1 == A[l])) continue;
        else A[l-1]++;
    }

    for (auto i: A) {cout << i << ' ';} cout << endl;
    
    
}