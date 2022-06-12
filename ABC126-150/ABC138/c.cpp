#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<double> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    
    for (int i = 0; i < n-2; i++) {
       sort(v.begin(), v.end());
       v.push_back((v[0] + v[1]) / 2.0);
       v.erase(v.begin(), v.begin()+2);
    }

    cout << (v[0] + v[1]) / 2.0 << endl;
}