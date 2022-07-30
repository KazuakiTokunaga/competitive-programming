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
    
    vector<int> A(N);
    rep(i, 0, N) cin >> A[i];

    vector<int> dislikes(N, 0);
    rep(i, 0, K){
        int b;
        cin >> b; b--;
        dislikes[b] = 1;
    }
    
    int m = *max_element(all(A));
    bool possible = false;
    rep(i, 0, N){
        if (A[i] == m) if (dislikes[i]) possible = true;
    }

    if (possible) cout << "Yes" << endl;
    else cout << "No" << endl;
}