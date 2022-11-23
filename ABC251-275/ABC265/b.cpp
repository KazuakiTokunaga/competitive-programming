#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define all(x) (x).begin(),(x).end()

int main() {
    int N, M; ll T;
    cin >> N >> M >> T;
    
    vector<int> A(N-1);
    rep(i, 0, N-1) cin >> A[i];
    
    vector<pii> Bonus;
    rep(i, 0, M){
        int x, y;
        cin >> x >> y; x--;
        Bonus.push_back({x, y});
    }

    int b_idx = 0;
    rep(i, 0, N-1){

        if (b_idx < M and i == Bonus[b_idx].first){
            T += Bonus[b_idx].second;
            b_idx++;
        }

        T -= A[i];
        if (T <= 0){
            cout << "No" << endl;
            return 0;
        }
        
    }

    cout << "Yes" << endl;
    return 0;
}