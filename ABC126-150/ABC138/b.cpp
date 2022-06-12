#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    int a;
    double res;
    for (int i = 0; i < n; i++) {
        cin >> a;
        res += 1.0/a;
    }

    cout << 1.0/res << endl;
}