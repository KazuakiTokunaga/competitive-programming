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
    
    reverse(all(A));
    int cnt = 0;
    int accum = 0;
    rep(i, 0, N){
        accum += A[i];
        if (accum >= 4) cnt++;
    }
    cout << cnt << endl;
}