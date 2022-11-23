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
    

    rep(i, 0, N) rep(j, i+1, N) rep(k, j+1, N){
        if (A[i] + A[j] + A[k] == 1000){
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
}