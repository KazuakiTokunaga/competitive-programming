#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int n;
    cin >> n;

    vector<int> l(n);
    for (int i = 0; i < n; i++) cin >> l[i];

    sort(l.begin(), l.end());
    
    int ans = 0;
    for (int i = 2; i < n; i++) {
        int max_e = l[i];
        auto next_iter = l.begin()+ (i-1);    
        auto min_iter = lower_bound(l.begin(), l.end(), (max_e - *next_iter + 1));
        if (min_iter > next_iter) {
            min_iter = next_iter;
        }
        ans += next_iter - min_iter;
        // cout << "(max_iter, next_iter, min_iter, ans) = " << max_e << " " << *next_iter << " " << *min_iter << " " << next_iter - min_iter << endl;

        next_iter--;;
        while (next_iter > min_iter){
            if (*next_iter + *min_iter <= max_e){
                min_iter++;
                continue;
            }
            if (*next_iter + *min_iter > max_e){
                ans += next_iter - min_iter;
                // cout << "(max_iter, next_iter, min_iter, ans) = " << max_e << " " << *next_iter << " " << *min_iter << " " << next_iter - min_iter << endl;
                next_iter--;
                continue;
            }
        }
    }

    cout << ans << endl;
}