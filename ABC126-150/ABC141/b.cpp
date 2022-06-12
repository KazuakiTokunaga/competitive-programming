#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    bool ans = true;
    for (int i = 0; i < s.length(); i++) {
        if ((i+1) % 2 == 0 and s[i] == 'R'){
            ans = false;
        }
        if ((i+1) % 2 == 1 and s[i] == 'L'){
            ans = false;
        }
    }

    cout << (ans ? "Yes" : "No") << "\n";
}