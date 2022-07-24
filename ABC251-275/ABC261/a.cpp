#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
#define all(x) (x).begin(),(x).end()

int main() {
    int L1, R1, L2, R2;
    cin >> L1 >> R1 >> L2 >> R2;
    
    if (L1 > L2){
        swap(L1, L2);
        swap(R1, R2);
    }

    if (R2 < R1) cout << R2 - L2 << endl;
    else cout << max(0, R1 - L2) << endl;
}