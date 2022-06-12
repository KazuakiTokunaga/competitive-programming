#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    string s;
    cin >> s;

    string res = "Good";
    if (s[0] == s[1] or s[1] == s[2] or s[2] == s[3]){
        res = "Bad";
    }

    cout << res << endl;
}