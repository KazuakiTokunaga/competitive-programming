#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define all(x) (x).begin(),(x).end()

int main() {
    int N, K;
    cin >> N >> K;
    
    vector<vector<int>> A(N, vector<int>(2));
    rep(i, 0, N) cin >> A[i][0];
    rep(i, 0, N) cin >> A[i][1];
    
    vector<vector<int>> ng(N, vector<int>(2, 0));
    rep(i, 1, N){
        rep(j, 0, 2){
            int ok = 0;
            if (!ng[i-1][0]) if (abs(A[i][j] - A[i-1][0]) <= K) ok = 1;
            if (!ng[i-1][1]) if (abs(A[i][j] - A[i-1][1]) <= K) ok = 1;
            ng[i][j] = 1 - ok;
        }
    }

    if (ng[N-1][0] and ng[N-1][1]) cout << "No" << endl;
    else cout << "Yes" << endl;
}