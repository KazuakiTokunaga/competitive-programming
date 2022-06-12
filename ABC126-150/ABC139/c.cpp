#include <bits/stdc++.h>
using namespace std;
constexpr int INF = 1000000000 + 8;

int main() {
    int n;
    cin >> n;
    
    vector<int> h(n);
    for (int i = 0; i < n; i++) cin >> h[i];
    

    int res = 0, cur = -INF, count = 0;
    for (int i: h) {
        if (i <= cur){
            count += 1;
            res = max(res, count);
        } else {
            count = 0;
        }
        cur = i;
    }
    cout << res << endl;
}