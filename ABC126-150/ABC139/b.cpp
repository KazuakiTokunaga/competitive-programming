#include <bits/stdc++.h>
using namespace std;

int main() {
    int a,b;
    cin >> a >> b;
    
    int res = 0;
    res = ceil((b-1.0) / (a-1.0));

    cout << res << endl;
}