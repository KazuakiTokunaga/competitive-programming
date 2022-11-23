#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define all(x) (x).begin(),(x).end()

int main() {
    int Q;
    cin >> Q;
    
    multiset<ll> A;
    rep(i, 0, Q){
        int q; ll x;
        cin >> q >> x;

        if (q == 1) {A.insert(x); continue;}

        else if (q == 2){
            int k; cin >> k;

            auto iter = A.upper_bound(x);
            bool flag = true;
            while (k){
                if (iter == A.begin() and k){
                    cout << -1 << endl;
                    flag = false;
                    break;
                }
                k--; iter--;
            }
            if (flag) cout << *iter << endl;

        } else if (q == 3){
            int k; cin >> k; k--;

            auto iter = A.lower_bound(x);
            if (iter == A.end()) {cout << -1 << endl; continue;}
            
            bool flag = true;
            while (k){
                if (++iter == A.end() and k > 0) {
                    cout << -1 << endl;
                    flag = false;
                    break;
                }
                k--;
            }
            if (flag) cout << *iter << endl;
        }
    }
}