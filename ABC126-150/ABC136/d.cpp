#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    string s;
    cin >> s;
    int n = s.size();

    vector<int> r, l;
    int r_count = 0, l_count = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'R'){
            if (l_count == 0) r_count += 1;
            else {r_count += 1; l.push_back(l_count); l_count = 0;}
        }
        if (s[i] == 'L'){
            if (r_count == 0) l_count += 1;
            else {l_count += 1; r.push_back(r_count); r_count = 0;}
        }
    }
    l.push_back(l_count);

    for (int i = 0; i < r.size(); i++) {
        for (int j = 0; j < r[i]-1; j++) {
            cout << 0 << " ";
        }
        cout << ceil((double)r[i]/2) + l[i] / 2 << " ";
        cout << r[i]/2 + ceil((double)l[i]/2) << " ";
        for (int j = 0; j < l[i]-1; j++) {
            cout << 0 << " ";
        }
    }
    cout << endl;
}