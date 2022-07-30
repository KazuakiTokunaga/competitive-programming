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
    
    vector<vector<int>> B(K);
    rep(i, 0, N){
        int a;
        cin >> a;
        B[i % K].push_back(a);
    }

    rep(i, 0, K) sort(all(B[i]), greater<int>());

    int cur = 0, idx = 0;
    while (true){
        if (B[idx].empty()) break;

        int nxt = B[idx].back(); B[idx].pop_back();    
        if (nxt < cur){
            cout << "No" << endl;
            return 0;
        }
        else cur = nxt;

        idx = (idx+1) % K;
    }

    cout << "Yes" << endl;

}