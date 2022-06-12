#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)

int main() {
    int n;
    cin >> n;
    
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    ll total_sum = 0;
    rep(i, 0, n){
        total_sum += a[i];
    }

    ll sum_b = 0;
    rep(i, 0, n-1){
        if (i % 2 == 0){
            sum_b += 2 * a[i];
        }
    }

    vector<int> res(n);

    res[n-1] = total_sum - sum_b;
    rrep(i, n-2, 0){
        res[i] = (a[i] - res[i+1] / 2) * 2;
    }

    rep(i, 0, n){
        cout << res[i] << " ";
    }
    cout << endl;
}