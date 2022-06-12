#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    string s;
    cin >> s;

    map<char, int> m;
    for (int i = 0; i < s.size(); i++) {
        m[s[i]] += 1;
    }
    
    string res = "Yes";
    if (m.size() != 2) res = "No";
    for (auto itr = m.begin(); itr != m.end(); itr++) {
        if (itr->second != 2){
            res = "No";
        }
    }
    cout << res << endl;
}