#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int n;
    cin >> n;
    
    int res = 0;
    for (int i = 1; i < n+1; i++) {
        if (to_string(i).size() % 2 == 1){
            res += 1;
        }
    }

    cout << res << endl;
}