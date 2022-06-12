#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)

int main() {
    int n, K;
    cin >> n >> K;
    
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    
    int res = 0;
    rep(i, 0, n+1){
        rep(j, 0, n+1){
            
            if (n < i + j) continue;
            int rest = K - i - j;
            if (rest < 0) continue;
            int max_k = min(i+j, rest);

            rep(k, 0, max_k+1){

                vector<int> hands;
                rep(a, 0, i){
                    hands.push_back(v[a]);
                }
                rrep(a, n-1, n-j){
                    hands.push_back(v[a]);
                }

                sort(hands.begin(), hands.end());
                int s = accumulate(hands.begin(), hands.end(), 0);

                rep(a, 0, k){
                    s -= hands[a];
                }
                res = max(res, s);
            }
        }
    }

    cout << res << endl;
}