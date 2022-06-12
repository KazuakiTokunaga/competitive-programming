#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int n,l;
    cin >> n >> l;

    int res = 0;
    int mini = 10000;
    for (int i = 0; i < n; i++) {
        if (abs(mini) > abs(l+i)){
            mini = l+i;
        }
        res += l+i;
    }
    cout << res - mini << endl;
}