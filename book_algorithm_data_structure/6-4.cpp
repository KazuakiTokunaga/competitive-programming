//二分探索（lower_bound）

#include <bits/stdc++.h>
using namespace std;
#define ll long long
constexpr int INF = 1000000000;
int main() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    
    int m = INF;
    sort(b.begin(), b.end());

    // b に無限大を表す値 (INF) を追加しておく
    // これを行うことで、iter = b.end() となる可能性を除外する
    b.push_back(INF);

    for (int i = 0; i < n; i++) {
        auto iter = lower_bound(b.begin(), b.end(), k-a[i]);
        int val = *iter;
        cout << i << " " << val << endl;

        if (a[i] + val < m) {
            m = a[i] + val;
        }
    }
    cout << m << endl;
}