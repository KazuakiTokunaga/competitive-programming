#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int n,d;
    cin >> n >> d;

    vector<vector<int>> a(n, vector<int>(d));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < d; j++) {
            cin >> a[i][j];
        }
    }

    int res = 0;
    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            int dis = 0;
            for (int k = 0; k < d; k++) {
                dis += pow(a[i][k] - a[j][k], 2);
            }
            if (sqrt(dis) == (int)sqrt(dis)) {
                res += 1;
            }
        }
    }

    cout << res << endl;
}