#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define all(x) (x).begin(),(x).end()

int main() {
    vector<int> A(5);
    rep(i, 0, 5) cin >> A[i];
    
    int cnt1 = 1, cnt2 = 0, card = 0;
    rep(i, 1, 5){
        if (A[i] == A[0]) cnt1++;
        else if (!card){
            card = A[i];
            cnt2++;
        } else {
            if (A[i] != card) {cout << "No" << endl; return 0;}
            else cnt2++;
        }
    }

    if (max(cnt1, cnt2) == 3 and min(cnt1, cnt2) == 2) cout << "Yes" << endl;
    else cout << "No" << endl;
}