#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define all(x) (x).begin(),(x).end()

int main() {
    int N, X, Y;
    cin >> N >> X >> Y;
    
    vector<int> A(N);
    rep(i, 0, N) cin >> A[i];

    vector<vector<int>> Idx(5);
    
    Idx[0].push_back(-1);
    rep(i, 0, N){
        if (A[i] < Y) Idx[0].push_back(i);
        if (A[i] == Y) Idx[1].push_back(i);
        if (A[i] == X) Idx[2].push_back(i);
        if (A[i] > X) Idx[0].push_back(i);
    }
    Idx[0].push_back(N);
    Idx[1].push_back(N+1); Idx[2].push_back(N+1);
    
    ll res = 0;
    rep(i, 0, Idx[0].size()-1){
        int l = Idx[0][i];
        int r = Idx[0][i+1];

        int cur = l+1;
        while (cur < r){
            int ok = max(*lower_bound(all(Idx[1]), cur), *lower_bound(all(Idx[2]), cur));
            
            if (ok >= r) break;
            else res += r - ok;

            cur++;
        }
    }

    cout << res << endl;
}