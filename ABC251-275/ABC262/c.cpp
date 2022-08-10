#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define all(x) (x).begin(),(x).end()

int main() {
    int N;
    cin >> N;
    
    vector<int> A(N);
    rep(i, 0, N) cin >> A[i];

    ll same = 0;
    ll res = 0;
    rep(i, 1, N+1){
        if (i == A[i-1]) same++;
        else if (A[i-1] > i and A[A[i-1]-1] == i) res++;
    }
    res += same * (same-1) / 2;
    cout << res << endl;
}