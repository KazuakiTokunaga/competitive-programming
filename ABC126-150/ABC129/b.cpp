#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)

int main() {
    int n;
    cin >> n;

    vector<int> w(n);
    for (int i = 0; i < n; i++) cin >> w[i];
    
    vector<int> accum(n);
    partial_sum(w.begin(), w.end(), accum.begin());
    
    int total = accumulate(w.begin(), w.end(), 0);

    double min_diff = pow(10, 9);
    for (int i = 0; i < n; i++) {
        min_diff = min((double)min_diff, abs((double)total / 2 - accum[i]));
    }

    cout << 2 * min_diff << endl;

}