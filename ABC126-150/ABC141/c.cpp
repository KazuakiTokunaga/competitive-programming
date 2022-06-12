#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k, q;
    cin >> n >> k >> q;

    vector<int> asum(n);
    for (int i = 0; i < q; i++) {
        int a;
        cin >> a;
        asum[a-1] += 1;
    }

    for (int i = 0; i < n; i++) {
        if (asum[i] > (q-k)) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
}